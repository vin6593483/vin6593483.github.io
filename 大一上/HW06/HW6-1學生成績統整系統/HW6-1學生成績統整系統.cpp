#include<iostream>
using namespace std;
struct student {                                //依題目要求，先建立一個struct(我命名為student)
	char gender;                                //建立一欄性別，因為是字符用char形式
	float score;                                //接下來是分數欄，因為有可能有小數所以選擇float,double尤佳
};
int main(void) {                          //(一陣強烈的電吉他)進入主程式!
	student s[5];                         //首先先宣告建立一個陣列，以student的結構保存，然後裡頭可以存放五筆student結構的資料
	for (int i = 0; i < 5; i++) {         //這個for迴圈是為了讓使用者輸入這5筆student結構的資料
		cin >> s[i].gender >> s[i].score; //想要重複不費力，選for不會辜負你
	}                                     //先解釋思路!!!我的想法是每個性別都再叫兩塊記憶體，一塊負責計人數，一塊負責加總分數
	float boysum = 0, girlsum = 0;        //於是我這邊先宣告了float型態的計總和的記憶體
	int boycount = 0, girlcount = 0;      //再來是整數形式的計人數的記憶體
	for (int i = 0; i < 5; i++) {         //接下來因為也要重複作業(判斷男女)，所以再次寵幸for迴圈
		if (s[i].gender == 'b') {         //當發現是小男孩的時候就(嘿嘿嘿)在計人數那邊+1，同時把那筆資料給加到計總和的記憶體那邊
			boycount++;                   //上一行用'單引號'是因為我們宣告的gender是char(字符)類型，在電腦裡是按ASCII或是Unicode儲存的(041說過，佔1byte)，在我們cout的時候，用雙引號""是因為我們打得字是按string(字串)輸出的，簡單理解就是單引號叫char，雙引號string
			boysum = boysum + s[i].score;
		}
		else if (s[i].gender == 'g') {    //女生也做一次一樣的統計
			girlcount++;
			girlsum = girlsum + s[i].score;
		}
	}
	cout << (boysum / boycount) << "\n";    //最後直接輸出(總和/人數)就好
	cout << (girlsum / girlcount) << "\n";
	return 0;

}
