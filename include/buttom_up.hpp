#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
 
// ボトムアップ型微分積分用doubleクラス
class BU_double {
    // 変数値
    double val;
    // 偏導関数値
    double d_val;
public:
    // コンストラクタ
    BU_double(double v=0, double dv=0) {
        val = v;
        d_val = dv;
    }
    // 微分する入力変数として選択する関数
    void select(void) {
        d_val = 1.0;
    }
    // 変数値を返す
    double get_value(void) {
        return val;
    }
    // 偏導関数値を返す
    double get_d_value(void) {
        return d_val;
    }

    // 各種演算子の定義
    friend BU_double operator + (BU_double x, BU_double y) {
        return BU_double(x.val+y.val, x.d_val+y.d_val);
    }
    friend BU_double operator - (BU_double x, BU_double y) {
        return BU_double(x.val-y.val, x.d_val-y.d_val);
    }
    friend BU_double operator * (BU_double x, BU_double y) {
        return BU_double(x.val*y.val, x.d_val*y.val+x.val*y.d_val);
    }
    friend BU_double operator / (BU_double x, BU_double y) {
        double w = x.val/y.val;
        return BU_double(w, (x.d_val-w*y.d_val)/y.val);
    }
    friend BU_double operator + (BU_double x) {
        return BU_double(x.val, x.d_val);
    }
    friend BU_double operator - (BU_double x) {
        return BU_double(-x.val, -x.d_val);
    }
    friend bool operator < (BU_double x, BU_double y) {
        return x.val < y.val;
    }
    friend bool operator <= (BU_double x, BU_double y) {
        return x.val <= y.val;
    }
    friend bool operator > (BU_double x, BU_double y) {
        return x.val > y.val;
    }
    friend bool operator >= (BU_double x, BU_double y) {
        return x.val >= y.val;
    }
    
    // 基本関数の定義
    friend BU_double sqrt(BU_double x) {
        return BU_double(sqrt(x.val), 0.5*x.d_val/sqrt(x.val));
    }
    friend BU_double exp(BU_double x) {
        return BU_double(exp(x.val), x.d_val*exp(x.val));
    }
    friend BU_double log(BU_double x) {
        return BU_double(log(x.val), x.d_val/x.val);
    }
    friend BU_double sin(BU_double x) {
        return BU_double(sin(x.val), cos(x.val));
    }
    friend BU_double cos(BU_double x) {
        return BU_double(cos(x.val), -sin(x.val));
    }

    // coutに出力するフォーマットの定義
    friend ostream& operator<<(ostream &s, BU_double x) {
        return s << "BU_double("<< x.val << ", " << x.d_val << ") ";
    }

};
