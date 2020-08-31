#include<iostream>
using namespace std;

class Person{
    // 주소
    string street_address, post_code, city;

    // 직업
    string company_name, position;
    int annual_income = 0;

    Person(){}
public:

	Person(Person&& other)
		: street_address{ move(other.street_address) },
		post_code{ move(other.post_code) },
		city{ move(other.city) },
		company_name{ move(other.company_name) },
		position{ move(other.position) },
		annual_income{ other.annual_income }
	{}

    friend class PersonBuilder;
};

class PersonBuilderBase {
protected:
    Person& person;
    explicit PersonBuilderBase(Person& person) : person{person}{}
public:
    operator Person const(){
        return move(person);
    }
};

class PersonBuilder : public PersonBuilderBase {
    Person n;
public:
    PersonBuilder() : PersonBuilderBase{n}{}

    
};

int main(){
    
    return 0;
}