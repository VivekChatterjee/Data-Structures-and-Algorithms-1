class Solution {
public:
    string intToRoman(int num) {
        string one[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string ten[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hun[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thous[]={"","M","MM","MMM"};
        return thous[num/1000] + hun[(num%1000)/100] + ten[(num%100)/10] + one[num%10];
    }
};