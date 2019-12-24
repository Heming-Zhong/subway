#include "subway.h"
#include "memu.h"
int main()
{
	
	subway_system system;
	while(Menu::isChecking())
	{
		Menu::printMenu();
		string origin = Menu::getOrigin();
		string destination = Menu::getDestination();
		if (system.isStaition(origin) && system.isStaition(destination))
			system.checkLine(origin, destination);
		else
		{
			clear();
			cout << "վ�㲻����\n";
			std::system("pause");
		}
	}
	return 0;
}
