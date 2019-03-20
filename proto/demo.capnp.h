#ifndef CAPN_A93FC509624C72D9
#define CAPN_A93FC509624C72D9
/* AUTO GENERATED - DO NOT EDIT */
#include <capnp_c.h>

#if CAPN_VERSION != 1
#error "version mismatch between capnp_c.h and generated code"
#endif

#ifndef capnp_nowarn
# ifdef __GNUC__
#  define capnp_nowarn __extension__
# else
#  define capnp_nowarn
# endif
#endif


#ifdef __cplusplus
extern "C" {
#endif

struct Person;
struct Person_PhoneNumber;
struct Date;

typedef struct {capn_ptr p;} Person_ptr;
typedef struct {capn_ptr p;} Person_PhoneNumber_ptr;
typedef struct {capn_ptr p;} Date_ptr;

typedef struct {capn_ptr p;} Person_list;
typedef struct {capn_ptr p;} Person_PhoneNumber_list;
typedef struct {capn_ptr p;} Date_list;

enum Person_PhoneNumber_Type {
	Person_PhoneNumber_Type_mobile = 0,
	Person_PhoneNumber_Type_home = 1,
	Person_PhoneNumber_Type_work = 2
};

struct Person {
	capn_text name;
	Date_ptr birthdate;
	capn_text email;
	Person_PhoneNumber_list phones;
};

static const size_t Person_word_count = 0;

static const size_t Person_pointer_count = 4;

static const size_t Person_struct_bytes_count = 32;

struct Person_PhoneNumber {
	capn_text number;
	enum Person_PhoneNumber_Type type;
};

static const size_t Person_PhoneNumber_word_count = 1;

static const size_t Person_PhoneNumber_pointer_count = 1;

static const size_t Person_PhoneNumber_struct_bytes_count = 16;

struct Date {
	int16_t year;
	uint8_t month;
	uint8_t day;
};

static const size_t Date_word_count = 1;

static const size_t Date_pointer_count = 0;

static const size_t Date_struct_bytes_count = 8;

Person_ptr new_Person(struct capn_segment*);
Person_PhoneNumber_ptr new_Person_PhoneNumber(struct capn_segment*);
Date_ptr new_Date(struct capn_segment*);

Person_list new_Person_list(struct capn_segment*, int len);
Person_PhoneNumber_list new_Person_PhoneNumber_list(struct capn_segment*, int len);
Date_list new_Date_list(struct capn_segment*, int len);

void read_Person(struct Person*, Person_ptr);
void read_Person_PhoneNumber(struct Person_PhoneNumber*, Person_PhoneNumber_ptr);
void read_Date(struct Date*, Date_ptr);

void write_Person(const struct Person*, Person_ptr);
void write_Person_PhoneNumber(const struct Person_PhoneNumber*, Person_PhoneNumber_ptr);
void write_Date(const struct Date*, Date_ptr);

void get_Person(struct Person*, Person_list, int i);
void get_Person_PhoneNumber(struct Person_PhoneNumber*, Person_PhoneNumber_list, int i);
void get_Date(struct Date*, Date_list, int i);

void set_Person(const struct Person*, Person_list, int i);
void set_Person_PhoneNumber(const struct Person_PhoneNumber*, Person_PhoneNumber_list, int i);
void set_Date(const struct Date*, Date_list, int i);

#ifdef __cplusplus
}
#endif
#endif
