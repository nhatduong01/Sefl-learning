#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std;
// TODO
const int EVENT_SIZE = 100;
const int MAX_CHARACTER_EACH_LINE = 250;


// list of events
enum Event
{
    BOWSER_SURRENDED,
    MADBEAR,
    BANDIT,
    LORDLUPIN,
    ELF,
    TROLL,
    SHAMAN,
    SIREN_VAJSH,
    GET_EXCALIBUR,
    GET_MYTHRIL,
    GET_EXCALIPOOR,
    MUSHMARIO,
    MUSHFIB,
    MUSHGHOST,
    MUSHKNIGHT,
    GET_REMEDY,
    GET_MAIDENKISS,
    GET_PHOENIXDOWN,
    MERLIN,
    ABYSS,
    GUINEVERE,
    GET_LIGHTWING,
    ODIN,
    GET_DRAGON_SWORD,
    MEET_BOWSER = 99
};

//list of statuses
enum Status
{
    NORMAL,
    TINY,
    FROG
};

//list of portions to use
enum Portion
{
    PHOENIXDOWN,
    REMEDY,
    MAIDENKISS
};

//list of all type of fighters
enum Fighter
{
    NORMAL_KNIGHT,
    DRAGON_KNIGHT,
    PALADIN,
    LANCELOT,
    ARTHUR
};

//list of all weapons
enum Weapon
{
    NORMAL_SWORD,
    EXCALIPOOR,
    EXCALIBUR,
    DRAGON_SWORD,
    NORMAL_ARMOR,
    MYTHRIL
};


struct knight
{
   int HP;
   int maxHP;
   int level;
   int remedy;
   int maidenkiss;
   int phoenixdown;

   int fighter;     // type of fighter (specified in Fighter)

   int status = NORMAL;        // current status (specified in Status)
   int counter = 0;     //the index of the event when the curse started
   int old_level;   //the level of the knight before turning into frog

   int odin_tracker = -10;   //remains negative if Odin is not active
                                //become positive if Odin is activated
   int sword = NORMAL_SWORD;
   int armor = NORMAL_ARMOR;
};

// read data from input file to corresponding variables
// return 1 if successfully done, otherwise return 0
int readFile(const char* filename, knight& theKnight, int& nEvent, int* arrEvent)
{
	const char* file_name = filename;
	FILE* f = 0;
	char* str = new char[MAX_CHARACTER_EACH_LINE];
	int num;

	f = fopen(file_name, "r");
	if (f == NULL)	//file not found || cannot read
		return 0;

	fgets(str, MAX_CHARACTER_EACH_LINE, f);
	if (feof(f))
		return 0;

	int start = 0;
	int len = strlen(str);
	// read HP
	while (start < len && str[start] == ' ')
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.HP = num;
	if (theKnight.HP < 1 || theKnight.HP > 999)
		return 0;

	// read level
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.level = num;
	if (theKnight.level < 1 || theKnight.level > 10)
		return 0;

	// read remedy
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.remedy = num;
	if (theKnight.remedy < 0 || theKnight.remedy > 99)
		return 0;

	// read maidenkiss
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.maidenkiss = num;
	if (theKnight.maidenkiss < 0 || theKnight.maidenkiss > 99)
		return 0;

	// read phoenixdown
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.phoenixdown = num;
	if (theKnight.phoenixdown < 0 || theKnight.phoenixdown > 99)
		return 0;

	// read events
	nEvent = 0;
	while (1){
		if (feof(f))
			break;
		fgets(str, MAX_CHARACTER_EACH_LINE, f);
		if (str == NULL)
			break;
		start = 0;
		len = strlen(str);
    // cout << "\'" << str << "\'" << "\t" << len << endl;
		while (start < len){
			while (start < len && (str[start] > '9' || str[start] < '0'))
				start++;
			if (start >= len)
				break;
			arrEvent[nEvent] = 0;
			while (start < len && str[start] <= '9' && str[start] >= '0'){
				arrEvent[nEvent] = arrEvent[nEvent] * 10 + str[start] - '0';
				start++;
			}
			nEvent++;
		}
    delete[] str;
	}
	fclose(f);
	return 1;
}

void display(int* nOut)
{
  if (nOut)
    cout << *nOut;
  else
    cout << "Error!";
}

// TODO

// functions to work with fighters
namespace FighterHandler
{
    // supporting functions
    bool IsPrime(int number)
    {
        if (number < 2)
            return false;
        for(int i=2; i<=sqrt(number); i++)
        {
            if (number % i == 0)
                return false;
        }
        return true;
    }

    bool PythagoreanTriple(int number)
    {
        for(int i=1; i <= number/3; i++)
        {
           for (int j=i; j <= (number-i-j); j++)
           {
               if ( i*i + j*j == (number -i -j)*(number-i-j) )
                    return true;
           }
        }
        return false;
    }

    //determine the type of fighter ( must be called at the beginning )
    void Determine(knight &theKnight)
    {
        if (theKnight.HP == 999)
            theKnight.fighter = ARTHUR;
        else if (theKnight.HP == 888)
            theKnight.fighter = LANCELOT;
        else if (IsPrime(theKnight.HP))
            theKnight.fighter = PALADIN;
        else if (PythagoreanTriple(theKnight.HP))
            theKnight.fighter = DRAGON_KNIGHT;
        else
            theKnight.fighter = NORMAL_KNIGHT;
    }

    //check the current state of Lancelot
    void CheckLancelot(knight &theKnight)
    {
        if(theKnight.level % 2 == 0)
            theKnight.fighter = -LANCELOT;
        else
            theKnight.fighter = LANCELOT;
    }

}

//functions to work with portions
namespace PortionHandler
{
    void BackToNormal(knight &theKnight)
    {
        if(theKnight.status == TINY)
        {
            theKnight.HP *= 5;
            if (theKnight.HP > theKnight.maxHP)
                theKnight.HP = theKnight.maxHP;

            theKnight.status = NORMAL;
        }
        else if (theKnight.status == FROG)
        {
            theKnight.level = theKnight.old_level;
            theKnight.status = NORMAL;
        }

    }

    // automatically check and use portions
    void AutoUse(knight &theKnight)
    {
        if (theKnight.HP <= 0 && theKnight.phoenixdown > 0)
        {
            theKnight.phoenixdown--;

            if (theKnight.status != NORMAL)
                BackToNormal(theKnight);

            theKnight.HP = theKnight.maxHP;
        }

        else if (theKnight.status == TINY && theKnight.remedy > 0)
        {
            theKnight.remedy--;
            BackToNormal(theKnight);
        }

        else if(theKnight.status == FROG && theKnight.maidenkiss > 0)
        {
            theKnight.maidenkiss--;
            BackToNormal(theKnight);
        }
    }

    void PickUp(knight &theKnight, int portion)
    {
        switch(portion)
        {
            case PHOENIXDOWN:
                if(theKnight.phoenixdown < 99)
                    theKnight.phoenixdown++;
                break;
            case REMEDY:
                if(theKnight.remedy < 99)
                    theKnight.remedy++;
                break;
            case MAIDENKISS:
                if(theKnight.maidenkiss < 99)
                    theKnight.maidenkiss++;
                break;
        }
    }
}

//functions to work with status
namespace StatusHandler
{
    void Curse(knight &theKnight, int status)
    {
        if(status == TINY)
        {
            theKnight.status = TINY;
            if (theKnight.armor != MYTHRIL)
            {
                if(theKnight.HP < 5)
                    theKnight.HP = 1;
                else
                    theKnight.HP /= 5;
            }
        }
        else if (status == FROG)
        {
            theKnight.status = FROG;
            theKnight.old_level = theKnight.level;
            theKnight.level = 1;
        }

        theKnight.counter = 0;
    }

    void BackToNormal(knight &theKnight)
    {
        if(theKnight.status == TINY)
        {
            theKnight.HP *= 5;
            if (theKnight.HP > theKnight.maxHP)
                theKnight.HP = theKnight.maxHP;
        }
        else if (theKnight.status == FROG)
        {
            theKnight.level = theKnight.old_level;
        }
        theKnight.status = NORMAL;
    }


    void CurseTracker(knight &theKnight)
    {
        if (theKnight.status != NORMAL)
        {

            if (theKnight.counter < 3)
                theKnight.counter++;
            else //  curse expired
            {
                BackToNormal(theKnight);
            }
        }
    }
}

// functions needed to work with events
namespace EventHandler
{
    //supporting functions
    bool IsPerfectSquare(int number)
    {
        int root = (int) sqrt(number);
        if (root*root == number)
            return true;
        else
            return false;
    }

    int NearestFibonacci(int number)
    {
        int c = 1;
        while(true)
        {
            if ( IsPerfectSquare(5*(number+c)*(number+c)+4) || IsPerfectSquare(5*(number+c)*(number+c)-4) )
                return number+c;

            c += 1;
        }
    }

    int CalculateN(knight &theKnight)
    {
        return theKnight.HP + theKnight.level + theKnight.remedy + theKnight.maidenkiss + theKnight.phoenixdown;
    }

}


int main(int argc, char** argv)
{
    if (argc < 2) return 1;
    const char* filename = argv[1];;

   struct knight theKnight;
   int nEvent; //number of events
   int* arrEvent = new int[EVENT_SIZE]; // array of events
   int* nOut;                           // final result
   int i;

	readFile(filename, theKnight, nEvent, arrEvent);

    // ---------------------Initializing steps--------------------------------

    theKnight.maxHP = theKnight.HP;             //set maxHP to initial HP
    FighterHandler::Determine(theKnight);      //determine the type of fighter
    nOut = new int(0);
    bool metGuinevere = false;                  //turn true if meet event 20
    int b, levelO;
    float baseDamage;
    //-------------------------------------------------------------------------

    for (i = 1; i <= nEvent; i++)
    {
        int theEvent = arrEvent[i-1];

        //----------------------BEFORE-EVENT CHECK-UP--------------------
        if (abs(theKnight.fighter) == LANCELOT)
            FighterHandler::CheckLancelot(theKnight);

        //-------------------------ENTER EVENT---------------------------
        switch (theEvent)
        {
            case BOWSER_SURRENDED:
                *nOut = EventHandler::CalculateN(theKnight);
                goto ended;

            case MADBEAR:
            case BANDIT:
            case LORDLUPIN:
            case ELF:
            case TROLL:
                b = i%10;
                levelO = i>6? (b> 5? b : 5) : b;

                if (   theKnight.sword == EXCALIBUR
                    || i <= theKnight.odin_tracker+3
                    || theKnight.fighter == ARTHUR
                    || theKnight.fighter == LANCELOT
                    || theKnight.fighter == PALADIN
                    ||(theKnight.fighter == DRAGON_KNIGHT && theKnight.sword == DRAGON_SWORD)
                    ||(theKnight.sword != EXCALIPOOR && levelO < theKnight.level)
                    )
                    {
                        if (theKnight.level < 10)
                            theKnight.level++;
                        else
                            theKnight.level = 10;

                        break;
                    }

                else if ( (theKnight.sword != EXCALIPOOR && levelO == theKnight.level)
                        || theKnight.armor == MYTHRIL
                        )
                    break;

                else
                {
                    switch(theEvent)
                    {
                        case(MADBEAR):      baseDamage = 1.0;    break;
                        case(BANDIT):       baseDamage = 1.5;    break;
                        case(LORDLUPIN):    baseDamage = 4.5;    break;
                        case(ELF):          baseDamage = 6.5;    break;
                        case(TROLL):        baseDamage = 8.5;    break;
                    }

                    theKnight.HP -= baseDamage*levelO*10;
                    break;
                }

            case SHAMAN:
            case SIREN_VAJSH:

                if (theKnight.status != NORMAL)
                    break;

                b = i%10;
                levelO = i>6? (b> 5? b : 5) : b;

                if (   i <= theKnight.odin_tracker+3
                    || theKnight.fighter == ARTHUR
                    || theKnight.fighter == LANCELOT
                    || theKnight.fighter == PALADIN
                    ||(theKnight.fighter == DRAGON_KNIGHT && theKnight.sword == DRAGON_SWORD)
                    ||(theKnight.sword != EXCALIPOOR && levelO < theKnight.level)
                    )
                    {
                        if (theKnight.level < 9)
                            theKnight.level += 2;
                        else
                            theKnight.level = 10;

                        break;
                    }

                else if (theKnight.sword != EXCALIPOOR && levelO == theKnight.level)
                        break;

                else
                {
                    if(theEvent == SHAMAN)
                        StatusHandler::Curse(theKnight,TINY);

                    else if (theEvent == SIREN_VAJSH)
                        StatusHandler::Curse(theKnight,FROG);

                    break;
                }


            case GET_EXCALIBUR:
                if (theKnight.sword != DRAGON_SWORD)
                    theKnight.sword = EXCALIBUR;
                break;


            case GET_MYTHRIL:
                theKnight.armor = MYTHRIL;
                break;


            case GET_EXCALIPOOR:
                if (   i <= theKnight.odin_tracker + 3
                    || theKnight.fighter == DRAGON_KNIGHT
                    || theKnight.fighter == ARTHUR
                    || theKnight.fighter == LANCELOT
                    || theKnight.fighter == PALADIN
                    || theKnight.level >= 5
                    )
                    break;
                else
                {
                    theKnight.sword = EXCALIPOOR;
                    break;
                }


            case MUSHMARIO:
                theKnight.HP += 50;
                if (theKnight.HP > theKnight.maxHP)
                    theKnight.HP = theKnight.maxHP;

                break;


            case MUSHFIB:
                theKnight.HP = EventHandler::NearestFibonacci(theKnight.HP);

                if (theKnight.HP > theKnight.maxHP)
                        theKnight.HP = theKnight.maxHP;

                break;


            case MUSHGHOST:
                if (   theKnight.armor == MYTHRIL
                    || i <= theKnight.odin_tracker + 3
                    ||(theKnight.fighter == DRAGON_KNIGHT && theKnight.sword == DRAGON_SWORD)
                    || theKnight.fighter == PALADIN
                    )
                        break;

                if (theKnight.HP < 51)
                    theKnight.HP = 1;
                else
                    theKnight.HP -= 50;

                break;


            case MUSHKNIGHT:
                if (theKnight.maxHP > 949)
                    theKnight.maxHP = 999;
                else
                    theKnight.maxHP += 50;

                theKnight.HP = theKnight.maxHP;

                break;


            case GET_REMEDY:
                PortionHandler::PickUp(theKnight,REMEDY);
                break;


            case GET_MAIDENKISS:
                PortionHandler::PickUp(theKnight,MAIDENKISS);
                break;


            case GET_PHOENIXDOWN:
                PortionHandler::PickUp(theKnight,PHOENIXDOWN);
                break;


            case MERLIN:
                if (theKnight.status != NORMAL)
                    StatusHandler::BackToNormal(theKnight);

                if (theKnight.level < 10)
                    theKnight.level++;

                theKnight.HP = theKnight.maxHP;

                break;


            case ABYSS:
                if (   theKnight.level >= 7
                    || i <= theKnight.odin_tracker + 3
                    ||(theKnight.fighter == DRAGON_KNIGHT && theKnight.sword == DRAGON_SWORD)
                    )
                    break;
                else
                {
                    *nOut = -1;
                    if(theKnight.phoenixdown > 0)
                        theKnight.phoenixdown--;
                    goto ended;
                }


            case GUINEVERE:   //done
                metGuinevere = true;
                nEvent = 2*i-1;

                if (nEvent > 100)
                {
                    //reallocate array if number of rounds exceeds 100
                    int *temp = new int[nEvent];
                    copy(arrEvent, arrEvent + i, temp);
                    delete []arrEvent;
                    arrEvent = temp;
                }

                for(int j=0; j<(i-1); j++)
                    arrEvent[2*(i-1)-j] = arrEvent[j];

                break;


            case GET_LIGHTWING:
                if ( metGuinevere || nEvent <= i+3)
                {
                    *nOut = EventHandler::CalculateN(theKnight);
                    goto ended;
                }

                for (int j=(i+1); j<=(i+3); j++)
                {
                    if(arrEvent[j-1] == 0 || arrEvent[j-1] == 20)
                    {
                        *nOut = EventHandler::CalculateN(theKnight);
                        goto ended;
                    }
                }
                i += 3;
                break;



            case ODIN:
                if (theKnight.odin_tracker == -10)
                    theKnight.odin_tracker = i;
                break;



            case GET_DRAGON_SWORD:
                if (theKnight.fighter == DRAGON_KNIGHT)
                    theKnight.sword = DRAGON_SWORD;
                break;



            case MEET_BOWSER:
                if (    i <= theKnight.odin_tracker+3
                    || (theKnight.fighter == PALADIN && theKnight.level >= 8)
                    ||  theKnight.fighter == ARTHUR
                    || (theKnight.fighter == DRAGON_KNIGHT && theKnight.sword == DRAGON_SWORD)
                    ||  abs(theKnight.fighter) == LANCELOT
                    || (theKnight.level == 10 && theKnight.sword != EXCALIPOOR)
                    )
                    {
                        theKnight.level = 10;
                        break;
                    }
                else
                {
                    *nOut = -1;
                    if(theKnight.phoenixdown > 0)
                        theKnight.phoenixdown--;
                    goto ended;
                }

        }

        //----------------------- AFTER-EVENT CHECK UP--------------------------------
        //use portion if needed
        PortionHandler::AutoUse(theKnight);

        //check if knight is dead due to low HP
        if(theKnight.HP <= 0)
        {
            *nOut = -1;
            goto ended;
        }

        // keep track of current status
        StatusHandler::CurseTracker(theKnight);

    }

    if(*nOut == 0)
        *nOut = EventHandler::CalculateN(theKnight);

    ended:

    display(nOut);
    return 0;
}

