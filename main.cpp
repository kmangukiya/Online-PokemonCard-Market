//---------------------------------------------------
// Purpose: Test program for pokemon class.
// Authors: Kinal Mangukiya
//---------------------------------------------------

#include "pokemon.h"
#define collection_size 102
void display(pokemon pk[], int count);
void displaymvcard(pokemon pk[], int count);
void displaytotalworth(pokemon pk[], int count);
int buy(pokemon pk[], int count);
string trimming(string str);
void printtofile(pokemon pk[], int count);
void sell(pokemon pk[], int count);
pokemon pk[collection_size];
int count=0;

int main()
{
   
    ifstream din;
    ofstream dout;
    din.open("pokemon.txt");
   
    int line_count=0;
    while(!din.eof())
    {
        pk[count].read(din);
        count++;
    }
   din.close();
   for (int i=0; i<count;i++)
    {
        if(pk[i].getSalePrice()==0)
        {
            string newname = pk[i].getName()+"-SOLD";
            pk[i].setName(newname);
        }
    }
   
   int choice=0;
   while(1)
   {
    
   cout<<"\n##################################################################################################################\n";
   cout<<"\n\n 1. Display the cards in the collection\n 2. Display number of cards in the collection\n 3. Buy a new card\n 4. Sell a card\n 5. Display most vaulable card in the collection\n 6. Display the total worth of cards in the collection\n 7. Write card collection to output file\n 8. Quit\n\n";
   cout<<"Select your choice, enter number from the above choices: "; 
   cin>>choice;
   switch(choice)
   {
       case 1: display(pk, count); break;
       case 2: cout<<"\nThere are "<<count<<" cards in the collection.\n\n"; break;
       case 3: count=buy(pk, count); break;
       case 4: sell(pk, count);break;
       case 5: displaymvcard(pk, count); break;
       case 6: displaytotalworth(pk, count); break;
       case 7: printtofile(pk, count);break;
       case 8: cout<<"\n\nThank You!\n\n";exit(0); 
       default:cout<<"\nEnter choice as numbers from above list\n";
   }
   
   }
    return 0;
}

void display(pokemon pk[], int count)
{

    cout<<count<<endl;
    for (int i=0; i<count;i++)
    {
        pk[i].print();
    }
}

void displaymvcard(pokemon pk[], int count)
{
    
    int maxprice=-9999;
    for (int i; i<count;i++)
    {
        if(maxprice<pk[i].getPurchasePrice())
        {
            maxprice = pk[i].getPurchasePrice();
        }
    }
    
    for (int i; i<count;i++)
    {
      
        if(pk[i].getPurchasePrice() == maxprice)
        {
           cout<<"\n**Most valuable card in the collection**\n\n";
           pk[i].print();
        }
    }
    
    
}

void displaytotalworth(pokemon pk[], int count)
{
      
    int value=0;
    for (int i; i<count;i++)
    {
        value+=pk[i].getPurchasePrice();
    }
    
    cout<<"\n\nThe total worth of current Card colletion is: $"<<value<<"\n\n";
    
}

int buy(pokemon pk[], int count)

{
    int    number;
    string name;
    int    grade;
    string edition;
    float  purchase;
    float  sale;
    
    cout<<"\nEnter pokemon number: ";
    cin>>number;
    if (number >= 1 && number <= 102)
      pk[count].setNumber(number);
   else{
      cout << "Invalid pokemon number\n";
      return count;}
      
     cout<<"\nEnter the name of the pokemon: ";
    cin>>name;
    name = trimming(name);
   if (name.length() > 0)
      pk[count].setName(name);
   else{
      cout << "Invalid pokemon name\n";
      return count;}
     
      
     cout<<"\nEnter the grade of pokemon: ";
    cin>>grade;
    if (grade >= 1 && grade <= 10)
       pk[count].setGrade(grade);
   else{
      cout << "Invalid pokemon grade\n";
      return count;}
    
    
     cout<<"\nEnter pokemon edition: ";
    cin>>edition;
     edition = trimming(edition);
   if (edition == "First" || edition == "Shadowless" || edition == "Unlimited")
       pk[count].setEdition(edition);
   else{
      cout << "Invalid pokemon edition\n";
      return count;}
    
     cout<<"\nEnter purchase price of pokemon card: ";
    cin>>purchase;
    if (purchase >= 0)
      pk[count].setPurchasePrice(purchase);
   else{
      cout << "Invalid pokemon purchase price\n";
      return count;}
      
      
     cout<<"\nEnter selling price of pokemon card: ";
    cin>>sale;
     if (sale >= 0)
       pk[count].setSalePrice(sale);
   else{
      cout << "Invalid pokemon sale price\n";
      return count;}
    
    count++;
    return count;
}

void sell(pokemon pk[], int count)
{
    string name="";
    int number;
    cout<<"\nEnter the name of the pokemon card you want to sell: ";
    cin>>name;
    
    cout<<"\nEnter the card number of this pokemon in our collection: ";
    cin>>number;
    
     for (int i=0; i<count;i++)
    {
        if( (pk[i].getName()==name) && (pk[i].getNumber() == number) && (pk[i].getSalePrice())!=0 )
        {
            if(pk[i].getSalePrice()-pk[i].getPurchasePrice() >0)
            {
            cout<<"\nPokemon card sold!, Made a profit of $"<<(pk[i].getSalePrice()-pk[i].getPurchasePrice())<<" from this transaction\n";
            }
            else
            {
                cout<<"\nPokemon card sold at a loss of $"<<(pk[i].getPurchasePrice()-pk[i].getSalePrice())<<"\n";
            }
            name = name+"-SOLD";
            pk[i].setName(name);
            pk[i].setSalePrice(0);
            return;
            
        }
    }
    cout<<"\nPokemon Card not found in the collection\n";
    
}

void printtofile(pokemon pk[], int count)
{
    cout<<count<<endl;
    ofstream dout;
    dout.open("output.txt");
    for (int i=0; i<count;i++)
    {
        pk[i].write(dout);
    }
    dout.flush();
    dout.close();
}


string trimming(string str)
{
   // Remove unwanted spaces at end of string
   int pos = str.length()-1;
   while ((pos > 0) && (isspace(str[pos]))) pos--;
   str.erase(pos+1);
   return str;
}



