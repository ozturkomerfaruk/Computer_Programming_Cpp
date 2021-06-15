#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct course
{
	string ID;
	vector<int> grades;
	double average = 0;
};

void fillgroup (ifstream& ifs, vector<course>& groupinfo)
{
	course c;
	int grade, total;
	while(ifs)
	{
		ifs>> c.ID;
		c.grades.erase(c.grades.begin(), c.grades.end());
		if (!ifs) break;
		grade = 0;
		total = 0;
		while(ifs && grade != -999)
		{
			ifs >> grade;
			if (grade != -999)
			{
				total += grade;
				c.grades.push_back(grade);
			}
		}
		c.average = (float) total / (float)c.grades.size();
		groupinfo.push_back(c);
	}

}
int main()
{
	ifstream group1("group1.txt"), group2("group2.txt");
	ofstream ofs ("student.txt");
	vector<course> group1info, group2info;
	fillgroup(group1, group1info);
	fillgroup(group2, group2info);
	float group1avg = 0, group2avg = 0;
	ofs<< "                       Bar graph"<< endl;
	ofs<< "Course       course    0   10   20   30   40   50   60   70   80   90   100"<< endl;
	ofs<< "ID           Average   |....|....|....|....|....|....|....|....|....|....|"<< endl;
	for (int i = 0; i < group1info.size(); i++)
	{
		ofs<< setfill(' ');
		ofs<< left << setw(10)<< group1info[i].ID;
		ofs<< right<< setw(10)<< setprecision(4) << group1info[i].average<< "   ";
		ofs<< setfill('*') << left << setw((int)group1info[i].average/2)<< ""<< endl;
		ofs<< setfill(' ');
		ofs<< right<< std::setw(20)<< setprecision(4)<< group2info[i].average<< "   ";
		ofs<< setfill('#') << left << setw((int)group2info[i].average/2)<< ""<< endl<< endl;
		group1avg += (float)group1info[i].average;
		group2avg += (float)group2info[i].average;
	}

	
	group1avg /= (float)group1info.size();
	group2avg /= (float)group2info.size();
    ofs<< setfill(' ');
	ofs << left;
	ofs << "Group 1 -- ****"<< endl;
	ofs << "Group 2 -- ####"<< endl;
	ofs << "Avg for group 1" << right<< setw(10)<< setprecision(2) << group1avg<< endl;
	ofs << left;
	ofs << "Avg for group 2" << right<< setw(10)<< setprecision(2) << group2avg<< endl;
	return 0;
}
