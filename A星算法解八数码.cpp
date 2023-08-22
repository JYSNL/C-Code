#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class EightPuzzle
{
private:
    int num[9];
    int malposition;
    int depth;
    int evaluation;
public:
    EightPuzzle *parent;
    EightPuzzle *leaf_last;
    EightPuzzle *leaf_next;
public:
    EightPuzzle(int *num_input);
    void init(int *target);
    void setNum(int num[]);
    int *getNum();
    void getNum(int *num);
    int getMalposition()
    {
        return this->malposition;
    }
    int getDepth()
    {
        return this->depth;
    }
    int getEvaluation()
    {
        return this->evaluation;
    }
    void print();
    bool solvable(int *target);
    bool find_target(int *target);
    EightPuzzle& operator=(EightPuzzle& eightPuzzle);
    EightPuzzle& operator=(int other_num[9]);
    bool operator==(EightPuzzle& eigthPuzzle);
    bool operator==(int other_num[9]);
};

EightPuzzle::EightPuzzle(int *num_input)
{
    int ii;
    for (ii = 0; ii<9; ii++)
    {
        num[ii] = num_input[ii];
    }
    this->leaf_last = NULL;
    this->leaf_next = NULL;
    this->parent = NULL;
}

EightPuzzle& EightPuzzle::operator=(EightPuzzle& eightPuzzle)
{
    int ii;
    for (ii = 0; ii < 9; ii++)
    {
        this->num[ii] = eightPuzzle.getNum()[ii];
    }
    this->malposition = eightPuzzle.getMalposition();
    this->depth = eightPuzzle.getDepth() + 1;
    this->evaluation = this->malposition + this->depth;
    return *this;
}
EightPuzzle& EightPuzzle::operator=(int other_num[9])
{
    int ii;
    for (ii = 0; ii < 9; ii++)
    {
        num[ii] = other_num[ii];
    }
    return *this;
}
bool EightPuzzle::operator==(EightPuzzle& eightPuzzle)
{
    int match = 1;
    int ii;
    for (ii = 0; ii < 9; ii++)
    {
        if (this->num[ii] != eightPuzzle.getNum()[ii])
        {
            match = 0;
            break;
        }
    }
    if (match == 0)
        return false;
    else
        return true;
}
bool EightPuzzle::operator==(int other_num[9])
{
    int match = 1;
    int ii;
    for (ii = 0; ii < 9; ii++)
    {
        if (this->num[ii] != other_num[ii])
        {
            match = 0;
            break;
        }
    }
    if (match == 0)
        return false;
    else
        return true;
}

void EightPuzzle::init(int *target)
{
    int ii;
    int temp = 0;
    for (ii = 0; ii < 9; ii++)
    {
        if (num[ii] != target[ii])
        {
            temp++;
        }
    }
    this->malposition = temp;
    if (this->parent == NULL)
    {
        this->depth = 0;
    }
    else
    {
        this->depth = this->parent->depth + 1;
    }
    this->evaluation = this->malposition + this->depth;
}

void EightPuzzle::setNum(int num[])
{
    int ii;
    for (ii = 0; ii < 9; ii++)
    {
        this->num[ii] = num[ii];
    }
}

int *EightPuzzle::getNum()
{
    return this->num;
}

void EightPuzzle::getNum(int *num)
{
    int ii;
    for (ii = 0; ii < 9; ii++)
    {
        num[ii] = this->num[ii];
    }
}

bool EightPuzzle::solvable(int *target)
{
    int ii, ij;
    int count_num=0, count_target=0;
    for (ii = 0; ii < 9; ii++)
    {
        for (ij = 0; ij < ii; ij++)
        {
            if ((this->num[ij] < this->num[ii]) && (this->num[ij] != 0))
            {
                count_num++;
            }
            if (target[ij] < target[ii] && target[ij] != 0)
            {
                count_target++;
            }
        }
    }
    if ((count_num + count_target) % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool EightPuzzle::find_target(int *target)
{
    int ii;
    for (ii = 0; ii < 9; ii++)
    {
        if (this->num[ii] != target[ii])
        {
            break;
        }
    }
    if (ii == 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool move_up(int *num)
{
    int ii;
    for (ii = 0; ii < 9; ii++)
    {
        if (num[ii] == 0)
        {
            break;
        }
    }
    if (ii < 3)
    {
        return false;
    }
    else
    {
        num[ii] = num[ii - 3];
        num[ii - 3] = 0;
    }
    return true;
}

bool move_down(int *num)
{
    int ii;
    for (ii = 0; ii < 9; ii++)
    {
        if (num[ii] == 0)
        {
            break;
        }
    }
    if (ii > 5)
    {
        return 0;
    }
    else
    {
        num[ii] = num[ii + 3];
        num[ii + 3] = 0;
    }
    return true;
}

bool move_left(int *num)
{
    int ii;
    for (ii = 0; ii < 9; ii++)
    {
        if (num[ii] == 0)
        {
            break;
        }
    }
    if (ii == 0 || ii == 3 || ii == 6)
    {
        return false;
    }
    else
    {
        num[ii] = num[ii - 1];
        num[ii - 1] = 0;
    }
    return true;
}

bool move_right(int *num)
{
    int ii;
    for (ii = 0; ii < 9; ii++)
    {
        if (num[ii] == 0)
        {
            break;
        }
    }
    if (ii == 2 || ii == 5 || ii == 8)
    {
        return false;
    }
    else
    {
        num[ii] = num[ii + 1];
        num[ii + 1] = 0;
    }
    return true;
}

void EightPuzzle::print()
{
    int ii;
    for (ii = 0; ii<9; ii++)
    {
        if ((ii + 1) % 3 != 0)
        {
            cout << num[ii] << ",";
        }
        else
        {
            cout << num[ii] << endl;
        }
    }
}

bool existed(int *num, EightPuzzle *start)
{
    EightPuzzle *temp;
    for (temp = start; temp != NULL; temp = temp->parent)
    {
        if (*temp == num)
        {
            return true;
        }
    }
    return false;
}

EightPuzzle *best_route(EightPuzzle *start,EightPuzzle *target)
{
    EightPuzzle *temp, *best;
    temp = best = start;
    start->init(target->getNum());
    int min = start->getEvaluation();
    for (temp = start; temp != NULL; temp = temp->leaf_next)
    {
        if (min > temp->getEvaluation())
        {
            best = temp;
            min = temp->getEvaluation();
        }
    }
    return best;
}

void print_route(EightPuzzle *best,int list_length)
{
    int step = 0;
    EightPuzzle *temp;
    for (temp = best->parent; temp != NULL; temp = temp->parent)
    {
        cout << endl;
        temp->print();
        step++;
    }
    cout << endl << "The total steps is " << step << "." << endl;
    cout << endl << "The memory cost is " << list_length << "." << endl;
    return;
}

void proceeding(EightPuzzle &start, EightPuzzle &target)
{
    if (!start.solvable(target.getNum()))
    {
        cout <<endl<< "The serious number you input can't be solvable!" << endl;
        return;
    }
    EightPuzzle *best = &start;
    EightPuzzle *list = &start;
    EightPuzzle *apply,*temp;
    int num[9],list_length=0;
    while (best != NULL)
    {
        best = best_route(list,&target);
        if (best->find_target(target.getNum()))
        {
            print_route(best,list_length);
            return;
        }
        temp = best->leaf_last;
        best->getNum(num);
        if (move_up(num) && !existed(num, best))
        {
            apply = new EightPuzzle(num);
            apply->parent = best;
            apply->init(target.getNum());
            apply->leaf_last = temp;
            if (temp == NULL)
            {
                list = apply;
            }
            else
            {
                temp->leaf_next = apply;
            }
            temp = apply;
            list_length++;
        }
        best->getNum(num);
        if (move_down(num) && !existed(num, best))
        {
            apply = new EightPuzzle(num);
            apply->parent = best;
            apply->init(target.getNum());
            apply->leaf_last = temp;
            if (temp == NULL)
            {
                list = apply;
            }
            else
            {
                temp->leaf_next = apply;
            }
            temp = apply;
            list_length++;
        }
        best->getNum(num);
        if (move_left(num) && !existed(num, best))
        {
            apply = new EightPuzzle(num);
            apply->parent = best;
            apply->init(target.getNum());
            apply->leaf_last = temp;
            if (temp == NULL)
            {
                list = apply;
            }
            else
            {
                temp->leaf_next = apply;
            }
            temp = apply;
            list_length++;
        }
        best->getNum(num);
        if (move_right(num) && !existed(num, best))
        {
            apply = new EightPuzzle(num);
            apply->parent = best;
            apply->init(target.getNum());
            apply->leaf_last = temp;
            if (temp == NULL)
            {
                list = apply;
            }
            else
            {
                temp->leaf_next = apply;
            }
            temp = apply;
            list_length++;
        }
        temp->leaf_next = best->leaf_next;
        if (best->leaf_next != NULL)
        {
            best->leaf_next->leaf_last = temp;
        }
        best->leaf_next = best->leaf_last = NULL;
    }
}

void input(int num_init[])
{
    int ii, ij;
    cout << "Please input the initial state of the eight puzzle:" << endl;
    cout << "(0 for the blank)" << endl << endl;
    for (ii = 0; ii<9; ii++)
    {
        cin >> num_init[ii];
        if (num_init[ii]<0 || num_init[ii]>8)
        {
            cout << "Wrong number! Please input again:(0-8)" << endl;
            ii--;
        }
        for (ij = 0; ij<ii; ij++)
        {
            if (num_init[ii] == num_init[ij])
            {
                cout << "The number you inputed is duplicated! Try again:" << endl;
                ii--;
            }
        }
    }
}

int main(int argc, char **argv)
{
    double time;
    clock_t START, FINISH;
    while(1){
    int num_init[9];
    input(num_init);
    EightPuzzle *start = new EightPuzzle(num_init);
    int num_target[9] = { 1,2,3,8,0,4,7,6,5 };
    EightPuzzle *target = new EightPuzzle(num_target);
    
	
    cout << "The initial serial number is:" << endl;
    start->print();
    cout << "The target serial number is:" << endl;
    target->print();
    START = clock();
    proceeding(*start, *target);
    FINISH = clock();
    time = (double)(FINISH - START) * 1000 / CLOCKS_PER_SEC;
    cout << endl << "The total time cost to solve the puzzle is: ";
    cout<< time <<" millisecond."<< endl << endl;}
    return 0;
}

//216408753->18steps 
//150482367->24steps
//132456780->18steps 
//132804567->20steps
//265431870->null
//687503214->22steps
