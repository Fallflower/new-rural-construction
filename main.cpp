/*
 * @Author: Metaphor
 */
/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            佛祖保佑     永不宕机     永无BUG
 */
//#pragma execution_character_set("utf-8")
#include "AdjMultListNetwork.h"
using namespace std;

void ShowMenu()
{// 需要完善
    cout << "\n------Menu-------" << endl;
    cout << "1." << endl;
    cout << "2." << endl;
    cout << "3." << endl;
    cout << "4.----展示图-----" << endl;
    cout << "0.----退 出------" << endl;
    cout << "请选择功能: " << endl;
}
int k;
int main()
{
    AdjMultListNetwork MultCountry("E:/VSCode-projs/C_C++_files/Study_2/v_1.0/new-rural-construction/Input.txt");
    if (MultCountry.IsEmpty())
    {
        cerr << "Error: failed get network from file" << endl;
        return -1;
    }
    ShowMenu();
    cin >> k;
    switch (k)
    {
    case 1:
        {

            break;
        }
    case 2:
        {

            break;
        }
    case 3:
        {

            break;
        }
    case 4:
        {
            return -1;
            break;
        }
    default:
        break;
    }
    return 0;
}