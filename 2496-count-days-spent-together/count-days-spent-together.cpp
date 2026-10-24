class Solution {
public:
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int convert(string &s) {

        string m, d;
        m += s[0];
        m += s[1];

        d += s[3];
        d += s[4];

        int count = 0;
        int mm = 0, dd = 0;

        mm = stoi(m);
        dd = stoi(d);

        for (int i = 0; i < mm; i++)
            count += months[i];
        count += dd;
        
        return count;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arr1 = convert(arriveAlice);
        int leav1 = convert(leaveAlice);

        int arr2 = convert(arriveBob);
        int leav2 = convert(leaveBob);

        int arr = max(arr1, arr2);
        int leav = min(leav1, leav2);

        if(arr > leav)
            return 0;

        return leav - arr + 1;
    }
};