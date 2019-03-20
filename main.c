#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "capnp_c.h"
#include "demo.capnp.h"

#define TRANSFER_LENGTH_MAX (4096)

#define ASSERT_EQ(x, y) do {if(x == y) { } else {printf("Fatal error, Function:%s Line:%d\n", __func__, __LINE__);for(;;) {} }} while(0)

#define EXPECT_BASE(true) \
	do { \
		printf("[%d] Verifying...    Result: ", __LINE__); \
		if(true) { \
			printf("Successful!\n"); \
		} else { \
			printf("Error, Function:%s Line:%d\n", __func__, __LINE__); \
		} \
	} while(0)

#define EXPECT_EQ(x, y)  EXPECT_BASE(x == y)

#define EXPECT_CAPN_TEXT_EQ(std, ans) EXPECT_BASE(strcmp(std, (ans).str) == 0 && strlen(std) == (ans).len)

static capn_text chars_to_text(const char *chars) {
	capn_text t;
	t.len = (int) strlen(chars);
	t.str = chars;
	t.seg = NULL;

	return (t);
}

int main(int argc, char* argv[])
{
	uint8_t buf[TRANSFER_LENGTH_MAX];
	ssize_t sz = 0;

	const char *name = "Jan";
	const char *email = "jeehong2015@gmail.com";
	const struct Date birth = {
		.year = 1992,
		.month = 2,
		.day = 5,
	};
	const int16_t phone_numbers = 2;
	const char *phone0 = "17717032991";
	const char *phone1 = "03922819473";
	const struct Person_PhoneNumber pn0 = {
		.number = chars_to_text(phone0),
		.type = Person_PhoneNumber_Type_mobile,
	};
	const struct Person_PhoneNumber pn1 = {
		.number = chars_to_text(phone1),
		.type = Person_PhoneNumber_Type_home,
	};

	printf("Start processing!\nBuild time: %s,%s\n", __DATE__, __TIME__);
	/* Serializing */
	{
		struct capn c;
		capn_init_malloc(&c);
		capn_ptr cr = capn_root(&c);
		struct capn_segment *cs = cr.seg;
		struct Person p;

		p.name = chars_to_text(name);

		p.email = chars_to_text(email);

		p.birthdate = new_Date(cs);
		write_Date(&birth, p.birthdate);

		p.phones = new_Person_PhoneNumber_list(cs, 2);
		set_Person_PhoneNumber(&pn0, p.phones, 0);
		set_Person_PhoneNumber(&pn1, p.phones, 1);

		Person_ptr pp = new_Person(cs);
		write_Person(&p, pp);

		int setp_ret = capn_setp(capn_root(&c), 0, pp.p);
		ASSERT_EQ(0, setp_ret);

		sz = capn_write_mem(&c, buf, TRANSFER_LENGTH_MAX, 0 /* packed */);
		capn_free(&c);
	}
	printf("Final data length is %d byte(s)\n", sz);
	/* Deserializing */
	{
		struct capn rc;
		int init_mem_ret = capn_init_mem(&rc, buf, sizeof(buf), 0 /* packed */);
		ASSERT_EQ(0, init_mem_ret);
		Person_ptr rroot;
		struct Person rp;
		rroot.p = capn_getp(capn_root(&rc), 0 /* off */, 1 /* resolve */);
		read_Person(&rp, rroot);

		EXPECT_CAPN_TEXT_EQ(name, rp.name);
		EXPECT_CAPN_TEXT_EQ(email, rp.email);

		struct Date birthday;
		read_Date(&birthday, rp.birthdate);
		EXPECT_EQ(birth.year, birthday.year);
		EXPECT_EQ(birth.month, birthday.month);
		EXPECT_EQ(birth.day, birthday.day);

		EXPECT_EQ(phone_numbers, capn_len(rp.phones));

		struct Person_PhoneNumber rpn0;
		get_Person_PhoneNumber(&rpn0, rp.phones, 0);
		EXPECT_CAPN_TEXT_EQ(phone0, rpn0.number);
		EXPECT_EQ(pn0.type, rpn0.type);

		struct Person_PhoneNumber rpn1;
		get_Person_PhoneNumber(&rpn1, rp.phones, 1);
		EXPECT_CAPN_TEXT_EQ(phone1, rpn1.number);
		EXPECT_EQ(pn1.type, rpn1.type);

		capn_free(&rc);
	}
	printf("Successful!\n");
	return(0);
}
