#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the marcsCakewalk function below.
long marcsCakewalk(vector<int> calorie, int x, int n) 
{
int a;
    for (int i=0; i<(n-1); i++)
    {
        for (int j=i; j<(n-1); j++)
        {
            a = calorie[i];
            if(calorie[i]<calorie[j+1])
            {
                calorie[i] = calorie[j+1];
                calorie[j+1] = a;
            }
        }
    }
    for (int i=0; i<n; i++)
    {
        x = x + (pow(2,i)*calorie[i]);
    }
    int res = x;
    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int x=0;
    int n;
    cin >> n;
    if((n<1)||(n>40))
    {
        cout<<"Wrong input";
    }       
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string calorie_temp_temp;
    getline(cin, calorie_temp_temp);

    vector<string> calorie_temp = split_string(calorie_temp_temp);

    vector<int> calorie(n);

    for (int i = 0; i < n; i++) {
        int calorie_item = stoi(calorie_temp[i]);

        calorie[i] = calorie_item;
    }
    for (int i = 0; i < n; i++)
    {
        if((calorie[i]<1)||(calorie[i]>1000))
    {
        cout<<"Wrong input";
    }
    }
    long result = marcsCakewalk(calorie, x, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

