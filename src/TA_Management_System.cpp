//TA_Management_System.cpp

#include <fstream>
#include <vector>
#include "TA.h"

/* Example file
7
8281954 Giulio Cesare Grad 11 2018
2783632 Aymen Alum 11 2018
5352622 Daksh UGrad 8 2019
7603086 Mia UGrad 5 2020
9345631 Nancy Alum 13 2014
1703358 John Grad 12 2015
2342686 Sofiane Grad 12 2015
*/
std::vector<std::string>  Separate_String(std::string source);
void Filtering_Files(std::string Path);
int main()
{
	try
	{
		//name of the file is test.txt
		std::cout << "Enter the name of the file" << std::endl;
		std::string test = "";
		std::cin >> test;
		Filtering_Files(test);
	}
	catch (char const* error)
	{
		std::cerr << error;
	}
	catch (const std::string error)
	{
		std::cerr << error;
	}
}

//Filter out alumni student from a text file then output the corrected data back to the original file from the class ta
void Filtering_Files(std::string Path)
{
	using namespace std;
	vector <TA> TA_vec;

	ifstream Infile;
	Infile.open(Path);
	if (!Infile || Path == "" || Path.find(".txt") == std::string::npos)
	{
		string temp = "";
		if (!Infile)
			temp += "Error : error while opening output file \n";
		if (Path == "")
			temp += "Error : empty Location \n";
		else if (Path.find(".txt") == std::string::npos)
			temp += "Error : Wrong file format \n";
		throw temp;
	}
	else
	{
		string line;
		int id, num;
		Infile >> num;
		int const size = num;

		std::cout << num << endl;
		while (getline(Infile, line))
		{
			std::vector <std::string> tem_vec = Separate_String(line);

			if (tem_vec.size() == 5)
			{
				TA temp_Ta(stoi(tem_vec.at(0)), tem_vec.at(1), tem_vec.at(2), stoi(tem_vec.at(3)), stoi(tem_vec.at(4)));
				TA_vec.push_back(temp_Ta);

			}
			else if (tem_vec.size() == 6)
			{
				TA temp_Ta(stoi(tem_vec.at(0)), tem_vec.at(1) + " " + tem_vec.at(2), tem_vec.at(3), stoi(tem_vec.at(4)), stoi(tem_vec.at(5)));
				TA_vec.push_back(temp_Ta);

			}

			std::cout << line << '\n';
		}
		Infile.close();
	}

	std::cout << "==========================================" << endl;

	ofstream outfile;
	outfile.open(Path);
	if (!outfile || TA_vec.size() == 0 || Infile.is_open() == true)
	{
		string temp = "";
		if (!outfile)
			temp += "Error : found while opening output file \n";
		if (TA_vec.size() == 0)
			temp += "Error : found Empty String vector \n";
		if (Infile.is_open() == true)
			temp += "Error : Failed to close input file \n";
		throw temp;
	}
	else
	{
		std::cout << TA_vec.size() << '\n';

		int size_of_non_alum = 0;
		for (size_t i = 0; i < TA_vec.size(); i++)
		{
			size_of_non_alum += (TA_vec[i].Is_Alum() == false) ? 1 : 0;
		}

		outfile << to_string(size_of_non_alum) + "\n";
		for (int i = 0; i < TA_vec.size(); i++)
		{

			if (TA_vec.at(i).Is_Alum() == false)
			{
				if (i == (TA_vec.size() - 1))
				{
					outfile << TA_vec[i].print();

				}
				else
				{
					outfile << TA_vec[i].print() + '\n';

				}
			}

		}
		outfile.close();
	}
	if (outfile.is_open() == true)
		throw "Error : Failed to close output file ";
}

std::vector<std::string>  Separate_String(std::string source)
{
	std::vector<std::string> vec;
	int size = 0;
	std::string temp = "";
	for (size_t i = 0; i < source.length(); i++)
	{
		if (source[i] == ' ')
		{
			size++;
			vec.push_back(temp);
			temp = "";
		}
		else if (i == (source.length() - 1))
		{
			vec.push_back(temp);

		}
		else
		{
			temp += source[i];
		}

	}
	if (size > 0)
	{
		std::string temp = "";
	}
	return vec;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
