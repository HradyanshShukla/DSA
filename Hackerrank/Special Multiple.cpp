#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);
string solve(int n) {
queue<long long>q;
q.push(9);
set<int>seen_reminders;
seen_reminders.insert(9%n);
while(!q.empty()){
    long long current_num=q.front();
    q.pop();
    int remainder=current_num%n;
    if(remainder==0){   
        return to_string(current_num);
    }
    long long next_num1=(current_num*10);
    long long next_num2=(current_num*10)+9;
    int rem1=next_num1%n;
    int rem2=next_num2%n;
    if(seen_reminders.find(rem1)==seen_reminders.end()){
        q.push(next_num1);
        seen_reminders.insert(rem1);
    }
    if(seen_reminders.find(rem2)==seen_reminders.end()){
        q.push(next_num2);
        seen_reminders.insert(rem2);
    }        
}
return "";
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string t_temp;
    getline(cin, t_temp);
    int t = stoi(ltrim(rtrim(t_temp)));
    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);
        int n = stoi(ltrim(rtrim(n_temp)));
        string result = solve(n);
        fout << result << "\n";
    }
    fout.close();
    return 0;
}
string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}
string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );
    return s;
}
