


#include<string>
#include"file.h"


int main()
{
	int ans;
	do
	{
		Note s;
		std::cout << "=========NOTE BOOK===========\n";
		std::cout << "1. Add Note\n2. view Notes\n3. open Note\n4. Search Note\n5. Edit Note\n6. Delete Note\n7. Exit\n";
		std::cin >> ans;
		if (ans == 1) 
		{
			
			s.addNote();
		}
		else if(ans ==2)
		{
			
			s.viewNotes();

		}
		else if (ans == 3)
		{
			s.opennote();
		}
		else if (ans == 4) 
		{
			s.searchNote();
		}
		else if (ans == 5)
		{
			s.editnote();
		}
		else if (ans == 6)
		{
			s.deleteNote();
		}
	} while (ans != 7);

}