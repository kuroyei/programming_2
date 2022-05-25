/*
  プログラミングII レポート課題5
  カレンダーを表示するプログラム
 */
#include <iostream>
#include <iomanip>
using namespace std;

// 曜日を表すための列挙型
enum Week{
  SUN,MON,TUE,WED,THU,FRI,SAT
};

// 日付を表すための構造体
struct Date{
  int year,month,day;
};

// ある日付の月の日数を計算し返却する
// @param d 日付構造体変数
// @return unsigned 日数
unsigned dayOfMonth(const Date& d){
  switch(d.month){
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 2:
      if(d.year%4==0 && !(d.year%100==0 && d.year%400!=0)){
        return 29;
      }
      return 28;
  }
}

// ある日付の曜日をZellerの公式を使って計算し，返却する
// @param d 日付構造体変数
// @return Week ある日にちの曜日
Week getWeek(const Date& d){
    double year,month,day;
  year = d.year;
  month = d.month;
  if(month==1 || month==2){
    --year;
    month+=12;
  }
  day = d.day;

  return static_cast<Week>( (int)(year+year/4-year/100+year/400+(13*month+8)/5+day) % 7 );
}

// ある日付の含まれる月のカレンダーを表示する
// @param d 日付構造体変数
void showCalendar(const Date& d){
  cout << d.year << '/' << d.month << '/' << d.day << endl;
  cout << " Su Mo Tu We Th Fr Sa" << endl;
  int w = 0;

  // 任意のdayからその月の1stの曜日を導くには？
  // getWeek(d) - d.day
  // if 220520
  // 20th is Fr = 5
  // 1st is Su = 0
  // (20-1)%7=19%7=19-14=5
  // 20th.week - 5 = 1st.week
  // if 220415
  // 15th is Fr = 5
  // 1st is Fr = 5
  // (15-1)%7=0

  // while(getWeek(date)!=static_cast<Week>(w)){

  while(((static_cast<int>(getWeek(d)) - (d.day-1)%7)+7)%7!=w){
    cout << setw(3) << ' ';
    w++;
  }


  for(int i=1;i<=dayOfMonth(d);i++){
    cout << setw(3) << i;

    if((w+1)%7==0){
      cout << endl;
    }
    w++;
  }
}

int main(void){
  Date today={2022,4,1};
  cin >> today.year;
  cin >> today.month;
  cin >> today.day;
  
  showCalendar(today);
  
  return 0;
}
