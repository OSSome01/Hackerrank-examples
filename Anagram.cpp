#include <cstring>
#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s, int c) 
{
    int m=0,count=0;
    string a,b;
    //int c = strlen(s);
    for(int i=0; i<c/2; i++)
    {
        a[i] = s[i];
        b[i] = s[i+(c/2)];
    }
    for(int i=0; i<c/2; i++)
    {
        cout<<"a1 "<<a[i]<<endl; 
       
    }
    for(int i=0; i<c/2; i++)
    {
        
        cout<<"b1 "<<b[i]<<endl; 
    }
    for(int i=0; i<c/2; i++)
    {
        for(int j=0; j<(c/2)-1; j++)
        {
            if(a[i]!=b[j])
                count++;
        }    
        if(count==(c/2))
        {
            
            m++;
        }
    }
    return m;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        
        getline(cin, s);
        int c = s.size();
        cout<<c<<endl;
        int result = anagram(s,c);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

