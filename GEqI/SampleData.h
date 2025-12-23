#ifndef SAMPLEDATA_H
#define SAMPLEDATA_H
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void insertSampleData(List<Equipment>& equipments, List<Consumable>& consumables)
{
	streambuf* original_cout_buffer = cout.rdbuf();
	streambuf* original_cin_buffer = cin.rdbuf();

	ostringstream output_dummy;
	cout.rdbuf(output_dummy.rdbuf());
	istringstream test_data;
	cin.rdbuf(test_data.rdbuf());

	test_data.str("\nTreadmill\nMachine\nAvailable\nGood\nBarbed wire\nDefense\nAvailable\nSharp\nDumbell\nWeights\nIn-use\nSweaty\n");
	equipments.AddToFront();
	equipments.AddToFront();
	equipments.AddToFront();

	test_data.clear();
	test_data.str("\nWater bottle\n16\n1.50\nCroissant\n5\n3.99\nChicken Tenders\n1\n5.00\n");
	consumables.AddToFront();
	consumables.AddToFront();
	consumables.AddToFront();

	cout.rdbuf(original_cout_buffer);
	cin.rdbuf(original_cin_buffer);
	cout << "\n=== sample data inserted ===\n\n";
}

#endif
