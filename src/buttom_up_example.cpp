#include <buttom_up.hpp>

#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    cout << setprecision(15);
    BU_double x, y;

    // sin(x)の微分 
    x = M_PI / 4;
    x.select();
    y = sin(x);
    cout << 2 * y.get_d_value() << endl; // 2016-07-13に修正

    
    // y = 10*x^2 のfor文を使ったアホな定義
    x = 5;
    y = 0;
    x.select();
    for(int i=0; i<10; ++i) y = y + x*x;
    // x = 5.0のときのyとdy/dxを出力
    cout << y << endl;

    // ニュートン法の実行
    x = 2.0; // 適当な初期値
    for(int i=0; i<10000; ++i) {
        x.select();
        // y = (x-sqrt(2))*(x^3+1)
        y = (x-sqrt(2))*(x*x+x+1);
        // yの値がdoubleの丸め誤差と同程度に小さければ終了
        if (y.get_value() < 1e-15) break;
        // ニュートン法の更新式で次のxを求める
        x = x - y.get_value()/y.get_d_value();
    }
    // x(=sqrt(2))を出力
    cout << x.get_value() << endl;
}
