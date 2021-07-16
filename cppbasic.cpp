/*
Problem Statement -
	There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. The cost of the edge can be the time the flight takes to reach city B from A, or the amount of fuel used for the journey. Represent this as a graph. The node can be represented by airport name or name of the city. Use adjacency matrix representation of the graph. Justify the storage representation used. 
*/

#include<iostream>
using namespace std;

const int MAX=30;

class Flight
{
	public :
	Flight *path;
	int id;
	string airport_name;
	int path_array[10][10];
	int fuel_array[10][10];
	int fuel_required;

	public :
				Flight()
				{
					path=NULL;
					airport_name="";
					fuel_required=0;
				}
				Flight(string airport_name,int fuel_required)
				{
					path=NULL;
					this->airport_name = airport_name;
					this->fuel_required = fuel_required;
				}
};

class CityGraph : public Flight
{
	Flight *route[MAX];
	int num;
	public :
	int fnum;
				CityGraph(int num)
				{
					this->num = num;
					for(int i=0;i<num;i++)
					{
						route[i]=NULL;
					}
					for(int i=0;i<10;i++)
					{
						for(int j=0;j<10;j++)
						{
							path_array[i][j]=0;
							fuel_array[i][j]=0;
						}
					}
				}
				int getAirportIndex(string a_name)
				{
					for(int i=0;i<num;i++)
					{
						if(route[i]->airport_name==a_name)
						{
							return i;
						}
					}
					return -1;
				}
				void addFlight(string source,string destination,int fuel)
				{
					Flight *s_airport;
					Flight *d_airport = new Flight(destination,fuel);
					int index = getAirportIndex(source);
					s_airport = route[index];
					while(s_airport->path!=NULL)
					{
						s_airport=s_airport->path;
					}
					s_airport->path = d_airport;
					int a1 = getAirportIndex(source); 
					int a2 = getAirportIndex(destination);
					path_array[a1][a2]=1;
					fuel_array[a1][a2]=fuel;
				}
				void displayFlights()
				{
					Flight *start;
					int fnum;
					for(int i=0;i<num;i++)
					{
						start=route[i];
						while(start!=NULL)
						{
							cout<<start->airport_name<<" ";
							start=start->path;
						}
						cout<<endl;
					}
				}
				void acceptFlightDetails()
				{
					string s_airport,d_airport;
					int fuel_cost;
					cout<<"\n----------Enter details of flight -----------";
					cout<<endl<<endl;
					for(int i=0;i<num;i++)
					{
						route[i] = new Flight;
						cout<<"Enter name of airport "<<i+1<<" : ";
						cin>>route[i]->airport_name;
						route[i]->id=i;
					}
					cout<<"\nEnter total number of flights : ";
					cin>>fnum;
					if(fnum<2)
					{
						cout<<"Minimum 2 flights must be there, incoming and outgoing!\n";
						return;						
					}
					else
					{
					for(int i=0;i<fnum;i++)
					{
						cout<<"\nEnter source airport : ";
						cin>> s_airport;
						cout<<"Enter destination airport : ";
						cin>>d_airport;
						cout<<"Enter amount of fuel required : ";
						cin>>fuel_cost;
						cout<<endl;
						addFlight(s_airport,d_airport,fuel_cost);
					}
					}
				}
				void displayMatrices()
				{	
					cout<<"\nAdjacency Matrix :- \n\n";
					for(int i=0;i<num;i++)
					{
						cout<<"\t\t"<<route[i]->airport_name<<"\t";
					}
					cout<<endl;
					for(int i=0;i<num;i++)
					{
						cout<<route[i]->airport_name;
						for(int j=0;j<num;j++)
						{
							cout<<"\t\t"<<path_array[i][j]<<"	";
						}
						cout<<endl;
						//cout<<route[i]->airport_name<<"	";
					}
					cout<<endl;
					
					cout<<"\nCost Matrix :- \n\n";
					for(int i=0;i<num;i++)
					{
						cout<<"\t\t"<<route[i]->airport_name<<"\t";
					}
					cout<<endl;
					for(int i=0;i<num;i++)
					{
						cout<<route[i]->airport_name;
						for(int j=0;j<num;j++)
						{
							cout<<"\t\t"<<fuel_array[i][j]<<"	";
						}
						cout<<endl;
						//cout<<route[i]->airport_name<<"	";
					}
					cout<<endl;
				}
};

int main()
{
	int number,choice;
	cout<<"Enter total number of airports : ";
	cin>>number;
	if(number<2)
	{
		cout<<"Minimum 2 airports are required for flights !!\n";
	}
	else
	{
	CityGraph graph(number);
	do
	{
		cout<<"------------------------------------------------\n\t\t\tMenu\n------------------------------------------------";
		cout<<"\n1. Add Flight.\n2. Display\n3. Adjacency Matrix and Cost Matrix\n4. Exit\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1 : graph.acceptFlightDetails();
						break;
			case 2 : graph.displayFlights();
						break;
			case 3 : graph.displayMatrices();
						break;
			case 4 : return 0;
						break;
			default : cout<<"Invalid Choice !";
		}
	}while(1);
}
	return 0;
}
/*
g++ -o a Assignment4.cpp
./a
Output -

Enter total number of airports : 3
------------------------------------------------
			Menu
------------------------------------------------
1. Add Flight.
2. Display
3. Adjacency Matrix and Cost Matrix
4. Exit
Enter your choice : 1

----------Enter details of flight -----------

Enter name of airport 1 : Pune
Enter name of airport 2 : Mumbai
Enter name of airport 3 : Nagar

Enter total number of flights : 3

Enter source airport : Pune
Enter destination airport : Nagar
Enter amount of fuel required : 500


Enter source airport : Pune 
Enter destination airport : Mumbai
Enter amount of fuel required : 200


Enter source airport : Mumbai      
Enter destination airport : Nagar
Enter amount of fuel required : 300

------------------------------------------------
			Menu
------------------------------------------------
1. Add Flight.
2. Display
3. Adjacency Matrix and Cost Matrix
4. Exit
Enter your choice : 3

Adjacency Matrix :- 

		Pune			Mumbai			Nagar	
Pune		0			1			1	
Mumbai		0			0			1	
Nagar		0			0			0	


Cost Matrix :- 

		Pune			Mumbai			Nagar	
Pune		0			200			500	
Mumbai		0			0			300	
Nagar		0			0			0	

------------------------------------------------
			Menu
------------------------------------------------
1. Add Flight.
2. Display
3. Adjacency Matrix and Cost Matrix
4. Exit
Enter your choice : 4
*/
