#include "mainwindow.h"
#include "test_runner.h"
#include "graph_algorithm/graph.h"
#include <QApplication>
#include <iostream>
#include <vector>
#include "graph_algorithm/edge.h"

void TestIsInteger()
{
    Assert(IsInteger("10"), "'10' is integer");
    Assert(IsInteger("0"), "'0' is integer");
    Assert(!IsInteger("10.0"), "'10.0' is double number");
    Assert(!IsInteger("asf"), "'asf' is not a number");
    Assert(!IsInteger("asf"), "'asf' is not a number");
    Assert(!IsInteger("100asf"), "'100asf' is not a number");
    Assert(!IsInteger("asf100"), "'asf100' is not a number");
    Assert(!IsInteger("   "), "'asf' is not a number");
}

void TestIsDouble()
{
    Assert(IsDouble("10"),"10 is double");
    Assert(IsDouble("10.0"), "10.0 is double");
    Assert(IsDouble("10.1202"), "10.1202 is double");
    Assert(IsDouble("0.1223"), "0.1223 is double");
    Assert(!IsDouble("0."), "The double number can not end with dot");
    Assert(!IsDouble(".102"), "The double number can not start with dot");
    Assert(!IsDouble("assd.sg"), "'assd.sg' isn`t a double");
    Assert(!IsDouble("120.3sfsd"), "The double number can not end with letters");
    Assert(!IsDouble("sfsd.12"), "The double number can not start with letters");
    Assert(!IsDouble("12yu.ygyu12"), "The double number can not contain letters");
    Assert(!IsDouble("12,5"), "As separator you can use only dot");
}

void TestBiggerQString()
{
    Assert(BiggerQString("aaaaa", "AAAAA"), "uppercase letters are smaller then lowercase 1");
    Assert(!BiggerQString("ZZZZZ", "aaaaa"), "uppercase letters are smaller then lowercase 1");
    Assert(BiggerQString("aaaab", "aaaaa"), "'aaaab' > 'aaaaa'");
    Assert(!BiggerQString("aaaaa", "aaaab"), "'aaaaa' < 'aaaab'");
    Assert(BiggerQString("aaaa", "aaa"), "If one word has size smaller then another word, first word is smaller");
    Assert(!BiggerQString("aa", "aaa"), "If one word has size bigger then another word, first word is bigger");
    Assert(BiggerQString("aaaaa", "aaaaZ"), "uppercase letters are smaller then lowercase 2");
    Assert(!BiggerQString("aaaaZ", "aaaaa"), "uppercase letters are smaller then lowercase 2");
    Assert(!BiggerQString("a", "a"), "Word are equals");
}

void TestSmallerQString()
{
    Assert(!SmallerQString("aaaaa", "AAAAA"), "uppercase letters are smaller then lowercase 1");
    Assert(SmallerQString("ZZZZZ", "aaaaa"), "uppercase letters are smaller then lowercase 2");
    Assert(!SmallerQString("aaaab", "aaaaa"), "'aaaab' > 'aaaaa'");
    Assert(SmallerQString("aaaaa", "aaaab"), "'aaaaa' < 'aaaab'");
    Assert(!SmallerQString("aaaa", "aaa"), "If one word has size smaller then another word, first word is smaller");
    Assert(SmallerQString("aa", "aaa"), "If one word has size bigger then another word, first word is bigger");
    Assert(!SmallerQString("aaaaa", "aaaaZ"), "uppercase letters are smaller then lowercase 1");
    Assert(SmallerQString("aaaaZ", "aaaaa"), "uppercase letters are smaller then lowercase 2");
    Assert(!SmallerQString("a", "a"), "Word are equals");
}

void TestAll()
{
    TestRunner tr;
    tr.RunTest(TestIsInteger, "TestIsInteger");
    tr.RunTest(TestIsDouble, "TestIsDouble");
    tr.RunTest(TestBiggerQString, "TestBiggerQString");
    tr.RunTest(TestSmallerQString, "TestSmallerQString");
}

using namespace std;
int main(int argc, char *argv[])
{
    TestAll();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();

}
