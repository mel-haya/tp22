#include "formes.hpp"

#define ARR_MAX 10
#define CARRE_ID  1
#define TRIANGLE_ID  2
#define CERCLE_ID  3

void add_forme(Forme **arr, int &i)
{

	if(i >= 10)
	{
		std::cout << std::endl << "Error: Table is full!" << std::endl;
		return;
	}
    Forme *ret;
	int input;
	char rotation;

	std::cout << std::endl << "Select a valid form:" << std::endl;
	std::cout << "1. carre" << std::endl;
	std::cout << "2. triangle" << std::endl;
	std::cout << "3. cercle" << std::endl << " > ";
	std::cin >> input ;
    if(input == CARRE_ID)
        arr[i] = new Carre();
    else if(input == TRIANGLE_ID)
        arr[i] = new Triangle();
    else if(input == CERCLE_ID)
        arr[i] = new Cercle();
	else
	{
		std::cout << "Error: Invalid form" << std::endl;
		return ; 
	}
	i++;
	std::cout << "Form added successfully" << std::endl;
}

int menu(void)
{
	int input;
	std::cout << "=========================" << std::endl;
	std::cout << "select a valid command :" << std::endl;
	std::cout << " 1. add form" << std::endl;
	std::cout << " 2. rotate a form" << std::endl;
	std::cout << " 3. display a form" << std::endl;
	std::cout << " 4. display all forms" << std::endl;
	std::cout << " 5. exit" << std::endl << " >";
	std::cin >> input;
	return input;
}

int main()
{
    Forme	*arr[ARR_MAX];
    int		i = 0;
	int		input;
	int		form_id;

	arr[0] = nullptr;
	while(1)
	{
		input = menu();
		if(input == 1)
			add_forme(arr, i);
		else if (input == 2 || input == 3)
		{
			if(!arr[0])
			{
				std::cout << std::endl << "Error: Table is empty!" << std::endl;
				continue;
			}
			form_id = -1;
			while(form_id < 0 || form_id > i)
			{
				std::cout << "Select a form from the array : ";
				std::cin >> form_id;
				if(form_id < 0 || form_id >= i)
					std::cout << "Error: out of bound !" << std::endl;
			}
			if(input == 2)
			{
				std::cout << "Form rotated successfully" << std::endl;
				arr[form_id]->rotation();
			}
			else
				arr[form_id]->afficher();
		}
		else if(input == 4)
		{
			if(!arr[0])
			{
				std::cout << std::endl << "Error: Table is empty!" << std::endl;
				continue;
			}
			for(int j = 0; j < i; j++)
				arr[j]->afficher();
		}
		else if(input == 5 || std::cin.eof())
		{
			std::cout << "Exit" << std::endl;
			exit(0);
		}
	}
	
}