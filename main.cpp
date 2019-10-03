//
//  main.cpp
//  BF_Full_Adder Project
//
//  Created by Brian Fernandez on 10/03/19.
//  Copyright © 2019 Brian Fernandez. All rights reserved.
// References
// https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//protoypes
int check_input1(string check1);
int check_input2(string check2);
char user_continue();
vector<bool>convertbinary1(string conv1);
vector<bool>convertbinary2(string conv2);
vector<bool>Full_adder(vector<bool>binary1, vector<bool>binary2);
int Display(vector<bool>answerconversion);

int main()
{
    cout<<"Brian Fernandez\n"<<"Full Adder\n";
    char continuation;
    vector<bool>boolbinary1;
    vector<bool>boolbinary2;
    vector<bool>answer;
    int check1 =0;
    int check2 =0;
    string input1; //input for first binary number
    
    do {
        cout<<"**************************************************\n";
        cout<< "User, input the first binary number: ";
        cin>>ws;
        getline(cin,input1);
        //cin>>input1;
        cout<<endl;
        check1 = check_input1(input1);
        while(check1 == 1)
        {
            cout<<endl;
            input1 = "0";
            cout<<"**************************************************\n";
            cout<< "User, input the first binary number: ";
            cin>>ws;
            getline(cin,input1);
            //cin>>input1;
            cout<<endl;
            check1 = check_input1(input1);
            
        }
        cout<<"**************************************************\n";
        string input2;//input for second binary number
        cout<< "User, input the second binary number: ";
        cin>>ws;
        getline(cin,input2);
        //cin>>input2;
        cout<<endl;
        check2 = check_input2(input2);
        while(check2 == 1)
        {
            cout<<endl;
            input2 = "0";
            cout<<"**************************************************\n";
            cout<< "User, input the second binary number: ";
            cin>>ws;
            getline(cin,input2);
            //cin>>input2;
            cout<<endl;
            check2 = check_input2(input2);
            
        }
        
        boolbinary1 = convertbinary1(input1);
        boolbinary2 = convertbinary2(input2);
        answer = Full_adder(boolbinary1,boolbinary2);
        cout<<input1<<" + "<<input2<< " = "<<Display(answer);
        continuation = user_continue();
        cout<<"**************************************************\n\n";
    }
    while((continuation == 'y') || (continuation == 'Y'));
    
    cout<<"**************************************";
    cout<<endl;
    
   return 0;
    
}
char user_continue()
{
    char answer;
    
    cout<<"Do you want to continue (Y/y)? ";
    cin>>answer;
    return answer;
}

int check_input1(string check1) // check that inputs are binary numbers
{
    char temp1;
    int check_1=0;
    for (int i=0;i < check1.length();i++) //loop iterations
    {
        temp1 =check1[i]; // grab binary digit @ index
        if (temp1 != '0')
        { //check each index if they're 0's and 1's
            if (temp1 != '1')
            {
                check_1 = 1;
            }
        }
    }
    if (check_1 == 1)
    {
        cout<<"The following characters are invalid: ";
        for (int i=0;i < check1.length();i++)
        {
            temp1 =check1[i]; // grab binary digit @ index
            if (temp1 != '0')
            { //check each index if they're 0's and 1's
                if (temp1 != '1')
                {
                    cout<<check1[i];
                }
            }
        }
    }
    
    return check_1;
}
int check_input2(string check2) // check that inputs are binary numbers
{
    char temp2;
    int check_2=0;
    for (int i=0;i < check2.length();i++) //loop iterations
    {
        temp2 =check2[i]; // grab binary digit @ index
        if (temp2 != '0')
        { //check each index if they're 0's and 1's
            if (temp2 != '1')
            {
                check_2 = 1;
            }
        }
    }
    
    if (check_2 == 1)
    {
        
        cout<<"The following characters are invalid: ";
        for (int i=0;i < check2.length();i++)
        {
            temp2 =check2[i]; // grab binary digit @ index
            if (temp2 != '0')
            { //check each index if they're 0's and 1's
                if (temp2 != '1')
                {
                    cout<<check2[i];
                }
            }
        }
        
    }
    return check_2;
}
vector<bool>convertbinary1(string conv1) // convert the 1's and 0's to bools
{
    bool value0 = false;
    bool value1 = true;
    char digit;
    // int temp;
    
    vector<bool> conversion1; //creating a vector to catch the conversions
    
    for (int i=0;i < conv1.length();i++)
    {
        digit = conv1[i];
        
        
        if (digit == '0')
        {
            conversion1.push_back(value0);
        }
        else
        {
            conversion1.push_back(value1);
        }
    }
    
    
    return conversion1;
}
vector<bool>convertbinary2(string conv2)
{
    bool value0 = false;
    bool value1 = true;
    char digit;
    vector<bool> conversion2;
    
    
    for (int i=0;i < conv2.length();i++)
    {
        digit =conv2[i];
        
        if (digit == '0')
        {
            conversion2.push_back(value0);
        }
        else
        {
            conversion2.push_back(value1);
        }
    }
    
    
    return conversion2;
    
}
vector<bool> Full_adder(vector<bool>binary1, vector<bool>binary2)
{
    vector<bool>answer;
    unsigned long length1 = binary1.size();
    unsigned long length2 = binary2.size();
    unsigned long length3; //new
    bool carry = false;
    bool temp = false;
    
    if (length1>length2)
    {
        length3 = length1;// this is to get the # of iterations
        do
        {
            binary2.insert(binary2.begin(), false);
            length2=binary2.size();
        }
        while (length2<length3);
    }
    
    else if (length2 > length1)
    {
        length3 = length2;
        do
        {
            binary1.insert(binary1.begin(), false);
            length1 = binary1.size();
        }
        while (length1<length3);
    }
    else
    {
        length3 = length1;
    }
    
    
    for (int i = 1;i < length3 + 1; i++)
    {
        temp = (binary1[length3-i] ^ binary2[length3-i]);
        answer.insert(answer.begin(), (temp^carry));
        
        if ((binary1[length3-i] && binary2[length3-i]) ||((binary1[length3-i]) && carry) || ((binary2[length3-i]) && carry) == true)
        {
            carry = true;
        }
        else
        {
            carry = false;
        }
    }
    
    if (carry == true)
    {
        answer.insert(answer.begin(),true);
    }
    return answer;
}
int Display(vector<bool>answerconversion)
{
    unsigned long size = answerconversion.size();
    
    for (int i = 0;i<size;i++)
    {
        if (answerconversion[i] == true)
        {
            cout<<'1';
        }
        else
            cout<<'0';
    }
    cout<<endl;
    return 0;
}
