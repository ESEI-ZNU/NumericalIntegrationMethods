//
// Created by Ярослав on 14.04.2023.
//

#ifndef NUMERICALINTEGRATIONMETHODS_CALCFUNCTIONAREA_H
#define NUMERICALINTEGRATIONMETHODS_CALCFUNCTIONAREA_H


class CalcFunctionArea {
public:
    static double getValueFunction(double x, int funcType);
private:
    static double integrateTrapezoidal(double a, double b, int n, int funcType);
};


#endif //NUMERICALINTEGRATIONMETHODS_CALCFUNCTIONAREA_H
