#include "demo.capnp.h"
/* AUTO GENERATED - DO NOT EDIT */
#ifdef __GNUC__
# define capnp_unused __attribute__((unused))
# define capnp_use(x) (void) x;
#else
# define capnp_unused
# define capnp_use(x)
#endif

static const capn_text capn_val0 = {0,"",0};

Person_ptr new_Person(struct capn_segment *s) {
	Person_ptr p;
	p.p = capn_new_struct(s, 0, 4);
	return p;
}
Person_list new_Person_list(struct capn_segment *s, int len) {
	Person_list p;
	p.p = capn_new_list(s, len, 0, 4);
	return p;
}
void read_Person(struct Person *s capnp_unused, Person_ptr p) {
	capn_resolve(&p.p);
	capnp_use(s);
	s->name = capn_get_text(p.p, 0, capn_val0);
	s->birthdate.p = capn_getp(p.p, 3, 0);
	s->email = capn_get_text(p.p, 1, capn_val0);
	s->phones.p = capn_getp(p.p, 2, 0);
}
void write_Person(const struct Person *s capnp_unused, Person_ptr p) {
	capn_resolve(&p.p);
	capnp_use(s);
	capn_set_text(p.p, 0, s->name);
	capn_setp(p.p, 3, s->birthdate.p);
	capn_set_text(p.p, 1, s->email);
	capn_setp(p.p, 2, s->phones.p);
}
void get_Person(struct Person *s, Person_list l, int i) {
	Person_ptr p;
	p.p = capn_getp(l.p, i, 0);
	read_Person(s, p);
}
void set_Person(const struct Person *s, Person_list l, int i) {
	Person_ptr p;
	p.p = capn_getp(l.p, i, 0);
	write_Person(s, p);
}

Person_PhoneNumber_ptr new_Person_PhoneNumber(struct capn_segment *s) {
	Person_PhoneNumber_ptr p;
	p.p = capn_new_struct(s, 8, 1);
	return p;
}
Person_PhoneNumber_list new_Person_PhoneNumber_list(struct capn_segment *s, int len) {
	Person_PhoneNumber_list p;
	p.p = capn_new_list(s, len, 8, 1);
	return p;
}
void read_Person_PhoneNumber(struct Person_PhoneNumber *s capnp_unused, Person_PhoneNumber_ptr p) {
	capn_resolve(&p.p);
	capnp_use(s);
	s->number = capn_get_text(p.p, 0, capn_val0);
	s->type = (enum Person_PhoneNumber_Type)(int) capn_read16(p.p, 0);
}
void write_Person_PhoneNumber(const struct Person_PhoneNumber *s capnp_unused, Person_PhoneNumber_ptr p) {
	capn_resolve(&p.p);
	capnp_use(s);
	capn_set_text(p.p, 0, s->number);
	capn_write16(p.p, 0, (uint16_t) (s->type));
}
void get_Person_PhoneNumber(struct Person_PhoneNumber *s, Person_PhoneNumber_list l, int i) {
	Person_PhoneNumber_ptr p;
	p.p = capn_getp(l.p, i, 0);
	read_Person_PhoneNumber(s, p);
}
void set_Person_PhoneNumber(const struct Person_PhoneNumber *s, Person_PhoneNumber_list l, int i) {
	Person_PhoneNumber_ptr p;
	p.p = capn_getp(l.p, i, 0);
	write_Person_PhoneNumber(s, p);
}

Date_ptr new_Date(struct capn_segment *s) {
	Date_ptr p;
	p.p = capn_new_struct(s, 8, 0);
	return p;
}
Date_list new_Date_list(struct capn_segment *s, int len) {
	Date_list p;
	p.p = capn_new_list(s, len, 8, 0);
	return p;
}
void read_Date(struct Date *s capnp_unused, Date_ptr p) {
	capn_resolve(&p.p);
	capnp_use(s);
	s->year = (int16_t) ((int16_t)capn_read16(p.p, 0));
	s->month = capn_read8(p.p, 2);
	s->day = capn_read8(p.p, 3);
}
void write_Date(const struct Date *s capnp_unused, Date_ptr p) {
	capn_resolve(&p.p);
	capnp_use(s);
	capn_write16(p.p, 0, (uint16_t) (s->year));
	capn_write8(p.p, 2, s->month);
	capn_write8(p.p, 3, s->day);
}
void get_Date(struct Date *s, Date_list l, int i) {
	Date_ptr p;
	p.p = capn_getp(l.p, i, 0);
	read_Date(s, p);
}
void set_Date(const struct Date *s, Date_list l, int i) {
	Date_ptr p;
	p.p = capn_getp(l.p, i, 0);
	write_Date(s, p);
}
