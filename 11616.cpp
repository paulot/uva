#include <iostream>
#include <vector>

using namespace std;

int vals[] = {1000, 500, 100, 50, 10, 5, 1, -9999};
int inds[] = {0,1,2,3,4,5,6,7};

int get_val(char c, int arr[]) {
  switch(c) {
    case 'M': return arr[0];
    case 'D': return arr[1];
    case 'C': return arr[2];
    case 'L': return arr[3];
    case 'X': return arr[4];
    case 'V': return arr[5];
    case 'I': return arr[6];
    default: return arr[7];
  }
}

int fromr(string &r) {
  int count[7] = {0,0,0,0,0,0,0};
  int last = 999999;
  for (int i = 0; i < r.size(); i++) {
    int cval = get_val(r[i], vals);
    if (cval > last) {
      for (int n = 6; vals[n] < cval; n--)
        count[n] *= -1;
    }
    count[get_val(r[i], inds)]++;
    last = cval;
  }

  int ans = 0;
  for (int i = 0; i < 7; i++) {
    ans += count[i]*vals[i];
  }
  return ans;
}

string tor(int num) {
  if (num == 0) return "";
  if (num >= 1000) {
    string s(num/1000, 'M');
    return s + tor(num%1000);
  }
  if (num >= 500) {
    if (num >= 900) return "CM" + tor(num-900);
    else return "D" + tor(num-500);
  } else if (num >= 100) {
    if (num >= 400) return "CD" + tor(num-400);
    else return "C" + tor(num-100);
  } else if (num >= 50) {
    if (num >= 90) return "XC" + tor(num-90);
    else return "L" + tor(num-50);
  } else if (num >= 10) {
    if (num >= 40) return "XL" + tor(num-40);
    else return "X" + tor(num-10);
  } else if (num >= 5) {
    if (num == 9) return "IX";
    else return "V" + tor(num-5);
  } else if (num >= 1) {
    if (num == 4) return "IV";
    else return "I" + tor(num-1);
  }

  return "";
}
  

int main() {
  string r;
  while (cin >> r)
    if (get_val(r[0], vals) > 0)
      cout << fromr(r) << endl;
    else
      cout << tor(stoi(r)) << endl;

  return 0;

}

