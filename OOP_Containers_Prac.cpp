#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct FirstLast {
	string First, Last;
};

bool Smallest(map<int, FirstLast>& mp, int x) {
	int w = 0;
	bool res = false;
	vector<int> vec;
	for (auto& i : mp) {
		vec.push_back(i.first);
	}
	
	if(mp.size() != 0)
		w = *min_element(begin(vec), end(vec));

	if (w > x)
		res = true;

	return res;
}

string GetName(map<int, FirstLast>& mp, int x) {
	string name;
	for (auto& i : mp) {
		if (i.first <= x && i.second.First != "" )
			name = i.second.First;
	}

	return name;

}

string GetLast(map<int, FirstLast>& mp, int x) {
	string name;
	for (auto& i : mp) {
		if (i.first <= x && i.second.Last != "")
			name = i.second.Last;
	}
	return name;
}



class Person {
public:
	void ChangeFirstName(int year, const string& first_name) { 
		if (mp.count(year) == 0) {
			mp[year].First = first_name;
			mp[year].Last = "";
		}
		else
			mp[year].First = first_name;
		
	}
	void ChangeLastName(int year, const string& last_name) { 
		if (mp.count(year) == 0) {
			mp[year].Last = last_name;
			mp[year].First = "";
		}
		else
			mp[year].Last = last_name;
	}

	string GetFullName(int year) { 
		string str;
		if (Smallest(mp, year) || mp.size() == 0) {
			str = "Incognito";
		}
		else if (GetName(mp, year) != "" && GetLast(mp, year) == "")
			str = GetName(mp, year) + " with unknown last name";
		else if (GetName(mp, year) == "" && GetLast(mp, year) != "")
			str = GetLast(mp, year) + " with unknown first name";
		else
			str = GetName(mp,year) + " " + GetLast(mp, year);

		return str;
	}



private:
	
	map<int, FirstLast> mp;

};

int main() {

	Person person;
	//TEST #1
	int year = 1;
	person.ChangeFirstName(year, std::to_string(year) + "_first");
	person.ChangeLastName(year, std::to_string(year) + "_last");
	std::cout << "year: " << year << '\n';
	std::cout << person.GetFullName(year) << '\n';
	//TEST #2
	year = 2;
	person.ChangeFirstName(year, std::to_string(year) + "_first");
	person.ChangeLastName(year, std::to_string(year) + "_last");
	std::cout << "year: " << year << '\n';
	std::cout << person.GetFullName(year) << '\n';
	//TEST #3
	year = 3;
	person.ChangeFirstName(year, std::to_string(2) + "_first");
	person.ChangeLastName(year, std::to_string(2) + "_last");
	std::cout << "year: " << year << '\n';
	std::cout << person.GetFullName(year) << '\n';

}
	 
