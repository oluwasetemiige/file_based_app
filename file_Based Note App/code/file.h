#pragma once

#include<string>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<filesystem>
#include<limits>


namespace fs = std::filesystem;



struct Note
{
	std::string note;
	
	
	int id = 1;
	std::string	filename;
	std::string path;

	void addNote() {
		fs::create_directories("Notes");
		int id = 1;
		while (fs::exists("Notes/note_" + std::to_string(id) + ".txt"))
		{

			id++;

		}
		filename = "note_" + std::to_string(id) + ".txt";
		path = "Notes/" + filename;


		std::ofstream file(path);
		if (file.is_open()) {
			std::cout << "Enter Note: ";
			std::cin.ignore();
			std::getline(std::cin, note);
			file << note;
			std::cout << "Note Added!" << std::endl;
			std::cout << "saved as " << filename << "\n";

		}
		else
		{
			std::cout << "Error file handling...." << std::endl;
			std::cout << "Please contact our Help department" << std::endl;
		}
		file.close();
	}
	void viewNotes()
	{
		std::cout << "==============Notes Avaliable=================\n";
		for (const auto& entry : fs::directory_iterator("Notes")) {
			std::cout << entry.path().filename() << std::endl;
		}
	}


	void opennote()
	{
		if (!fs::exists("Notes")) {
			std::cout << "No Notes found\n";
			return;
		}

		for (const auto& entry : fs::directory_iterator("Notes")) {
			std::ifstream file(entry.path());

			if (file.is_open()) {
				std::cout << "================= " << entry.path().filename().string() << "===================\n";
				std::string line;
				while (getline(file, line)) {
					std::cout << line << std::endl;
				}
			}
			file.close();
		}
	}

	void searchNote()
	{
		std::string search;
		std::cout << "Enter Your KeyWord: ";
		std::cin >> search;
		for (const auto& entry : fs::directory_iterator("Notes")) {
			std::ifstream file(entry.path());
			std::string line;
			while (getline(file, line)) {
				if (line.find(search) != std::string::npos) {
					std::cout << "\nFound in: " << entry.path().filename().string() << "\n";
					std::cout << line << std::endl;
				}
			}
		}
	}

	void deleteNote()
	{
		std::string flete;

		std::cout << "Enter Note to Delete (Note: e.g note_1.txt): \n";
		std::cin >> flete;
		std::string path = "Notes/" + flete;
		
			if (fs::exists(path)) 
			{
				fs::remove(path);
				std::cout << "File Deleted Successfully\n";
				
			}
			else 
			{
				std::cout << "File Not Found!";
			}
		

	}


	void editnote() 
	{
		std::string edit;
		std::cout << "Enter note (e.g note_1.txt): \n";
		std::cin >> edit;
		std::string path = "Notes/" + edit;

		
		if (!fs::exists(path)) {
			std::cout << "File Not found\n";
		}
		std::ifstream readpath(path);
		std::string line;

		std::cout << "\n Current Note: \n";
		while (getline(readpath, line)) {
			std::cout << line << std::endl;
		}readpath.close();

		std::ofstream writepath(path);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::string newedit;
		std::cout << "Enter NOte(Add end or END for new line to finish): ";
		std::getline(std::cin, newedit);
		writepath << newedit;
		writepath.close();
		std::cout << "NOte Updated Successfully!\n";
		
		
	}

};
