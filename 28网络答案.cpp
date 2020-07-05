#include<iostream>
#include<string>
 
using namespace std;
 
const int NO_OF_CHARS = 256;//the numbers of input alphabet
 
int getNextState(const string &pat, int M, int state, int x)
{
    // If the character c is same as next character in pattern,
    // then simply increment state
    if (state < M && x == pat[state])
        return state+1;
 
    int ns, i;  // ns stores the result which is next state
 
    // ns finally contains the longest prefix which is also suffix
    // in "pat[0..state-1]c"
 
    // Start from the largest possible value and stop when you find
    // a prefix which is also suffix
    for (ns = state; ns > 0; ns--)
    {
        if(pat[ns-1] == x)
        {
            for(i = 0; i < ns-1; i++)
            {
                if (pat[i] != pat[state-ns+1+i])
                    break;
            }
            if (i == ns-1)
                return ns;
        }
    }
 
    return 0;
}
 
/* This function builds the TF table which represents Finite Automata for a
   given pattern  */
void compute_Transition_Function(const string &pat, int M, int TF[][NO_OF_CHARS])
{
    int state, x;
        for (state = 0; state <= M; ++state)
        for (x = 0; x < NO_OF_CHARS; ++x)//for each charater c in the inout alphabet table
           TF[state][x] = getNextState(pat, M,  state, x);
}
 
/* Prints all occurrences of pat in txt */
void Finite_Automata_search(const string &pat, const string &txt)
{
    int M = pat.length();
    int N = txt.length();
	
    int TF_len = M+1;
    //this is supported by C++11
	int TF[TF_len][NO_OF_CHARS];//the state of transform table, stores the states.
 
    compute_Transition_Function(pat, M, TF);//compute the state of Transition Function 
 
    // Process txt over FA.
    int state=0;//inite the state
    for (int i = 0; i < N; i++)
    {
       state = TF[state][txt[i]];
       cout << state << endl;
       if (state == M)
			cout<<"pattern found at index is:"<<i-M+1<<endl;
       
    }
}

int main()
{
   //string txt = "Finite Automata Algorithm: Finite Automata";
   //string pat = "shaif";
    string txt = "mississippi";
    string pat = "issip";
   Finite_Automata_search(pat, txt);
   system("pause");
   return 0;
}