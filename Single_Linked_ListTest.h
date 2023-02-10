#pragma once

#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
#include "Course.h"
#include "Node.h"
#include "Single_Linked_List.h"
#include <string>
#include <iostream>
//Include your classes header file(s) below and uncomment.
//#include "myClass.h"
//Include cxx test file! ->Project->Properties->Include directories arrow->click white space then options-> set directory.


class newCxxTest : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void test1SLLCConstructorPushback()
    {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions. 
        Course CItem1("CSC", 111.1, "Fall", 1, 2);
        Single_Linked_List<Course> ListTest1;
        ListTest1.push_back(CItem1);
        TS_ASSERT_EQUALS(ListTest1.get(0), CItem1);
    }
    void test2SLLCPushBackOrder() {
        Course CItem1("CSC", 111.1, "Fall", 1, 2);
        Course CItem2("CSC", 112.2, "Fall", 1, 2);
        Single_Linked_List<Course> ListTest1;
        ListTest1.push_back(CItem1);
        ListTest1.push_back(CItem2);
        TS_ASSERT_EQUALS(ListTest1.get(0), CItem1);
        TS_ASSERT_EQUALS(ListTest1.get(1), CItem2);
    }
    void test3SLLCPushFront()
    {
        Course CItem1("CSC", 111.1, "Fall", 1, 2);
        Course CItem2("MAT", 120.1, "Spring", 2, 3);
        Single_Linked_List<Course> ListTest1;
        ListTest1.push_front(CItem1);
        ListTest1.push_front(CItem2);
        TS_ASSERT_EQUALS(ListTest1.get(0), CItem2);
        TS_ASSERT_EQUALS(ListTest1.get(1), CItem1);
        TS_ASSERT_DIFFERS(ListTest1.get(0), ListTest1.get(1));

    }
    void test4SLLCInsert()
    {
        Course CItem1("CSC", 100.1, "Fall", 1, 2);
        Course CItem2("CSC", 110.1, "Fall", 1, 2);
        Course CItem3("MAT", 120.1, "Fall", 1, 2);
        Course CItem4("ENG", 130.1, "Fall", 1, 2);
        Single_Linked_List<Course> ListTest1;
        ListTest1.push_back(CItem1);
        ListTest1.push_back(CItem2);
        ListTest1.push_back(CItem4);
        ListTest1.insert(1, CItem3);
        TS_ASSERT_EQUALS(ListTest1.get(1), CItem3);
    }
    void test5SLLCSortedInsertGet()
    {
        Course CItem1("CSC", 100.1, "Fall", 1, 2);
        Course CItem2("CSC", 110.1, "Fall", 1, 2);
        Course CItem3("MAT", 120.1, "Fall", 1, 2);
        Course CItem4("ENG", 130.1, "Fall", 1, 2);
        Single_Linked_List<Course> ListTest1;
        ListTest1.push_back(CItem1);
        ListTest1.push_back(CItem2);
        ListTest1.push_back(CItem4);
        ListTest1.sortedInsert(CItem3);
        TS_ASSERT_EQUALS(ListTest1.get(2), CItem3);
    }
    void test6SLLCPopBackBack()
    {
        Course CItem1("CSC", 100.1, "Fall", 1, 2);
        Course CItem2("CSC", 110.1, "Fall", 1, 2);
        Course CItem3("MAT", 120.1, "Fall", 1, 2);
        Course CItem4("ENG", 130.1, "Fall", 1, 2);
        Single_Linked_List<Course> ListTest1;
        ListTest1.push_back(CItem1);
        ListTest1.push_back(CItem2);
        ListTest1.push_back(CItem4);
        ListTest1.push_back(CItem3);
        ListTest1.pop_back();
        TS_ASSERT_EQUALS(ListTest1.back(), CItem4);
    }
    void test7SLLCPopFrontFront()
    {
        Course CItem1("CSC", 100.1, "Fall", 1, 2);
        Course CItem2("CSC", 110.1, "Fall", 1, 2);
        Course CItem3("MAT", 120.1, "Fall", 1, 2);
        Course CItem4("ENG", 130.1, "Fall", 1, 2);
        Single_Linked_List<Course> ListTest1;
        ListTest1.push_back(CItem1);
        ListTest1.push_back(CItem2);
        ListTest1.push_back(CItem4);
        ListTest1.push_back(CItem3);
        ListTest1.pop_front();
        TS_ASSERT_EQUALS(ListTest1.front(), CItem2);
    }
    void test8SLLCSize()
    {
        Course CItem1("CSC", 100.1, "Fall", 1, 2);
        Course CItem2("CSC", 110.1, "Fall", 1, 2);
        Course CItem3("MAT", 120.1, "Fall", 1, 2);
        Course CItem4("ENG", 130.1, "Fall", 1, 2);
        size_t comp = 3;
        Single_Linked_List<Course> ListTest1;
        ListTest1.push_back(CItem1);
        ListTest1.push_back(CItem2);
        ListTest1.push_back(CItem4);
        ListTest1.push_back(CItem3);
        ListTest1.pop_back();
        TS_ASSERT_EQUALS(ListTest1.size(), comp);
    }
    void test9SLLCDestructorEmpty()
    {
        Course CItem1("CSC", 100.1, "Fall", 1, 2);
        Course CItem2("CSC", 110.1, "Fall", 1, 2);
        Course CItem3("MAT", 120.1, "Fall", 1, 2);
        Course CItem4("ENG", 130.1, "Fall", 1, 2);
        Single_Linked_List<Course> ListTest1;
        ListTest1.push_back(CItem1);
        ListTest1.push_back(CItem2);
        ListTest1.push_back(CItem3);
        ListTest1.push_back(CItem4);
        ListTest1.~Single_Linked_List();
        TS_ASSERT_EQUALS(ListTest1.empty(), true);
    }
    void test10SLLCRemove()
    {
        Course CItem1("CSC", 100.1, "Fall", 1, 2);
        Course CItem2("CSC", 110.1, "Fall", 1, 2);
        Course CItem3("MAT", 120.1, "Fall", 1, 2);
        Course CItem4("ENG", 130.1, "Fall", 1, 2);
        Single_Linked_List<Course> ListTest1;
        ListTest1.push_back(CItem1);
        ListTest1.push_back(CItem2);
        ListTest1.push_back(CItem4);
        ListTest1.push_back(CItem3);
        ListTest1.remove(1);
        TS_ASSERT_EQUALS(ListTest1.get(1), CItem4);
    }
    void test11SLLCFind()
    {
        Course CItem1("CSC", 100.1, "Fall", 1, 2);
        Course CItem2("CSC", 110.1, "Fall", 1, 2);
        Course CItem3("MAT", 120.1, "Fall", 1, 2);
        Course CItem4("ENG", 130.1, "Fall", 1, 2);
        size_t comp = 1;
        Single_Linked_List<Course> ListTest1;
        ListTest1.push_back(CItem1);
        ListTest1.push_back(CItem3);
        ListTest1.push_back(CItem4);
        ListTest1.sortedInsert(CItem2);
        TS_ASSERT_EQUALS(ListTest1.find(CItem2), comp);

    }
    void test12SLLIConstructorPushback()
    {
        int IItem1 = 1;
        Single_Linked_List<int> ListTest1;
        ListTest1.push_back(IItem1);
        TS_ASSERT_EQUALS(ListTest1.get(0), 1);
    }
    void test13SLLIPushBackOrder()
    {
        int IItem1 = 1;
        int IItem2 = 5;
        Single_Linked_List<int> ListTest1;
        ListTest1.push_back(IItem1);
        ListTest1.push_back(IItem2);
        TS_ASSERT_EQUALS(ListTest1.get(0), 1);
        TS_ASSERT_EQUALS(ListTest1.get(1), 5);
    }
    void test14SLLCPushFront()
    {
        int IItem1 = 1;
        int IItem2 = 5;
        Single_Linked_List<int> ListTest1;
        ListTest1.push_front(IItem1);
        ListTest1.push_front(IItem2);
        TS_ASSERT_EQUALS(ListTest1.get(0), 5);
        TS_ASSERT_EQUALS(ListTest1.get(1), 1);
        TS_ASSERT_DIFFERS(ListTest1.get(0), ListTest1.get(1));

    }
    void test15SLLIInsert()
    {
        int IItem1 = 1;
        int IItem2 = 5;
        int IItem3 = 30;
        int IItem4 = 400;
        Single_Linked_List<int> ListTest1;
        ListTest1.push_back(IItem1);
        ListTest1.push_back(IItem2);
        ListTest1.push_back(IItem4);
        ListTest1.insert(1, IItem3);
        TS_ASSERT_EQUALS(ListTest1.get(1), 30);
    }
    void test16SLLISortedInsertGet()
    {
        int IItem1 = 1;
        int IItem2 = 5;
        int IItem3 = 30;
        int IItem4 = 400;
        Single_Linked_List<int> ListTest1;
        ListTest1.push_back(IItem1);
        ListTest1.push_back(IItem2);
        ListTest1.push_back(IItem4);
        ListTest1.sortedInsert(IItem3);
        TS_ASSERT_EQUALS(ListTest1.get(2), 30);
    }
    void test17SLLIPopBackBack()
    {
        int IItem1 = 1;
        int IItem2 = 5;
        int IItem3 = 30;
        int IItem4 = 400;
        Single_Linked_List<int> ListTest1;
        ListTest1.push_back(IItem1);
        ListTest1.push_back(IItem2);
        ListTest1.push_back(IItem4);
        ListTest1.push_back(IItem3);
        ListTest1.pop_back();
        TS_ASSERT_EQUALS(ListTest1.back(), 400);
    }
    void test18SLLCPopFrontFront()
    {
        int IItem1 = 1;
        int IItem2 = 5;
        int IItem3 = 30;
        int IItem4 = 400;
        Single_Linked_List<int> ListTest1;
        ListTest1.push_back(IItem1);
        ListTest1.push_back(IItem2);
        ListTest1.push_back(IItem4);
        ListTest1.push_back(IItem3);
        ListTest1.pop_front();
        TS_ASSERT_EQUALS(ListTest1.front(), 5);
    }
    void test19SLLISize()
    {
        int IItem1 = 1;
        int IItem2 = 5;
        int IItem3 = 30;
        int IItem4 = 400;
        size_t comp = 3;
        Single_Linked_List<int> ListTest1;
        ListTest1.push_back(IItem1);
        ListTest1.push_back(IItem2);
        ListTest1.push_back(IItem4);
        ListTest1.push_back(IItem3);
        ListTest1.pop_front();
        TS_ASSERT_EQUALS(ListTest1.size(), comp);
    }
    void test20SLLIDestructorEmpty()
    {
        int IItem1 = 1;
        int IItem2 = 5;
        int IItem3 = 30;
        int IItem4 = 400;
        Single_Linked_List<int> ListTest1;
        ListTest1.push_back(IItem1);
        ListTest1.push_back(IItem2);
        ListTest1.push_back(IItem4);
        ListTest1.push_back(IItem3);
        ListTest1.~Single_Linked_List();
        TS_ASSERT_EQUALS(ListTest1.empty(), true);
    }
    //void test21SLLIRemove()
    //{
    //    int IItem1 = 1;
    //    int IItem2 = 5;
    //    int IItem3 = 30;
    //    int IItem4 = 400;
    //    Single_Linked_List<int> ListTest1;
    //    ListTest1.push_back(IItem1);
    //    ListTest1.push_back(IItem2);
    //    ListTest1.push_back(IItem4);
    //    ListTest1.push_back(IItem3);
    //    ListTest1.remove(1);
    //    TS_ASSERT_EQUALS(ListTest1.get(1), 30);
    //}
    void test22SLLIFind()
    {
        int IItem1 = 1;
        int IItem2 = 5;
        int IItem3 = 30;
        int IItem4 = 400;
        size_t comp = 1;
        Single_Linked_List<int> ListTest1;
        ListTest1.push_back(IItem1);
        ListTest1.push_back(IItem4);
        ListTest1.push_back(IItem3);
        ListTest1.sortedInsert(IItem2);
        TS_ASSERT_EQUALS(ListTest1.find(IItem2), comp);
    }
    //void test23SLLIFindException()
    //{
    //    int IItem1 = 1;
    //    int IItem2 = 5;
    //    int IItem3 = 30;
    //    int IItem4 = 400;
    //    Single_Linked_List<int> ListTest1;
    //    ListTest1.push_back(IItem1);
    //    ListTest1.push_back(IItem4);
    //    ListTest1.push_back(IItem3);
    //    ListTest1.push_back(IItem2);
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.find(7));
    //}
    //void test24SLLIRemoveException()
    //{
    //    int IItem1 = 1;
    //    int IItem2 = 5;
    //    int IItem3 = 30;
    //    int IItem4 = 400;
    //    Single_Linked_List<int> ListTest1;
    //    ListTest1.push_back(IItem1);
    //    ListTest1.push_back(IItem4);
    //    ListTest1.push_back(IItem3);
    //    ListTest1.push_back(IItem2);
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.remove(10));
    //}
    //void test25SLLIGetException()
    //{
    //    int IItem1 = 1;
    //    int IItem2 = 5;
    //    int IItem3 = 30;
    //    int IItem4 = 400;
    //    Single_Linked_List<int> ListTest1;
    //    ListTest1.push_back(IItem1);
    //    ListTest1.push_back(IItem4);
    //    ListTest1.push_back(IItem3);
    //    ListTest1.push_back(IItem2);
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.get(10));
    //}
    //void test26SLLIInsertException()
    //{
    //    int IItem1 = 1;
    //    int IItem2 = 5;
    //    int IItem3 = 30;
    //    int IItem4 = 400;
    //    Single_Linked_List<int> ListTest1;
    //    ListTest1.push_back(IItem1);
    //    ListTest1.push_back(IItem4);
    //    ListTest1.push_back(IItem3);
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.insert(10, IItem2));
    //}
    //void test27SLLIEmptyException()
    //{
    //    int IItem1 = 1;
    //    //int IItem2 = 5;
    //    int IItem3 = 30;
    //    int IItem4 = 400;
    //    Single_Linked_List<int> ListTest1;
    //    ListTest1.push_back(IItem1);
    //    ListTest1.push_back(IItem4);
    //    ListTest1.push_back(IItem3);
    //    ListTest1.~Single_Linked_List();
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.empty());
    //}
    //void test28SLLIFrontException()
    //{
    //    int IItem1 = 1;
    //   // int IItem2 = 5;
    //    int IItem3 = 30;
    //    int IItem4 = 400;
    //    Single_Linked_List<int> ListTest1;
    //    ListTest1.push_back(IItem1);
    //    ListTest1.push_back(IItem4);
    //    ListTest1.push_back(IItem3);
    //    ListTest1.~Single_Linked_List();
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.front());
    //}
    //void test29SLLIBackException()
    //{
    //    int IItem1 = 1;
    //    //int IItem2 = 5;
    //    int IItem3 = 30;
    //    int IItem4 = 400;
    //    Single_Linked_List<int> ListTest1;
    //    ListTest1.push_back(IItem1);
    //    ListTest1.push_back(IItem4);
    //    ListTest1.push_back(IItem3);
    //    ListTest1.~Single_Linked_List();
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.back());
    //}
    //void test30SLLIPopBackException()
    //{
    //    int IItem1 = 1;
    //    //int IItem2 = 5;
    //    int IItem3 = 30;
    //    int IItem4 = 400;
    //    Single_Linked_List<int> ListTest1;
    //    ListTest1.push_back(IItem1);
    //    ListTest1.push_back(IItem4);
    //    ListTest1.push_back(IItem3);
    //    ListTest1.~Single_Linked_List();
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.pop_back());
    //}
    //void test31SLLIpopFrontException()
    //{
    //    int IItem1 = 1;
    //    //int IItem2 = 5;
    //    int IItem3 = 30;
    //    int IItem4 = 400;
    //    Single_Linked_List<int> ListTest1;
    //    ListTest1.push_back(IItem1);
    //    ListTest1.push_back(IItem4);
    //    ListTest1.push_back(IItem3);
    //    ListTest1.~Single_Linked_List();
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.pop_front());
    //}
    //void test32SLLDConstructorPushback()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    ListTest1.push_back(FItem1);
    //    TS_ASSERT_EQUALS(ListTest1.get(0), 1.1);
    //}
    //void test33SLLDPushBackOrder()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    float FItem2 = 5.55;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem2);
    //    TS_ASSERT_EQUALS(ListTest1.get(0), 1.1);
    //    TS_ASSERT_EQUALS(ListTest1.get(1), 5.55);
    //}
    //void test34SLLDPushFront()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    float FItem2 = 5.55;
    //    ListTest1.push_front(FItem1);
    //    ListTest1.push_front(FItem2);
    //    TS_ASSERT_EQUALS(ListTest1.get(0), 5.55);
    //    TS_ASSERT_EQUALS(ListTest1.get(1), 1);
    //    TS_ASSERT_DIFFERS(ListTest1.get(0), ListTest1.get(1));
    //}
    //void test35SLLDInsert()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    float FItem2 = 5.55;
    //    float FItem3 = 10.1010;
    //    float FItem4 = 453.322;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem2);
    //    ListTest1.push_back(FItem4);
    //    ListTest1.insert(1, FItem3);
    //    TS_ASSERT_EQUALS(ListTest1.get(1), 10.1010);
    //}
    //void test36SLLFSortedInsertGet()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    float FItem2 = 5.55;
    //    float FItem3 = 10.1010;
    //    float FItem4 = 453.322;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem3);
    //    ListTest1.push_back(FItem4);
    //    ListTest1.sortedInsert(FItem2);
    //    TS_ASSERT_EQUALS(ListTest1.get(1), 5.55);
    //}
    //void test37SLLFPopBackBack()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    float FItem2 = 5.55;
    //    float FItem3 = 10.1010;
    //    float FItem4 = 453.322;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem3);
    //    ListTest1.push_back(FItem4);
    //    ListTest1.push_back(FItem2);
    //    ListTest1.pop_back();
    //    TS_ASSERT_EQUALS(ListTest1.back(), 453.322);
    //}
    //void test38SLLFPopFrontFront()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    float FItem2 = 5.55;
    //    float FItem3 = 10.1010;
    //    float FItem4 = 453.322;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem2);
    //    ListTest1.push_back(FItem4);
    //    ListTest1.push_back(FItem3);
    //    ListTest1.pop_front();
    //    TS_ASSERT_EQUALS(ListTest1.front(), 10.1010);
    //}
    void test39SLLFSize()
    {
        Single_Linked_List<float> ListTest1;
        float FItem1 = 1.1;
        float FItem2 = 5.55;
        float FItem3 = 10.1010;
        float FItem4 = 453.322;
        size_t comp = 3;
        ListTest1.push_back(FItem1);
        ListTest1.push_back(FItem2);
        ListTest1.push_back(FItem4);
        ListTest1.push_back(FItem3);
        ListTest1.pop_front();
        TS_ASSERT_EQUALS(ListTest1.size(), comp);
    }
    void test40SLLFDestructorEmpty()
    {
        Single_Linked_List<float> ListTest1;
        float FItem1 = 1.1;
        float FItem2 = 5.55;
        float FItem3 = 10.1010;
        float FItem4 = 453.322;
        ListTest1.push_back(FItem1);
        ListTest1.push_back(FItem2);
        ListTest1.push_back(FItem4);
        ListTest1.push_back(FItem3);
        ListTest1.~Single_Linked_List();
        TS_ASSERT_EQUALS(ListTest1.empty(), true);
    }
    //void test41SLLFRemove()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    float FItem2 = 5.55;
    //    float FItem3 = 10.1010;
    //    float FItem4 = 453.322;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem2);
    //    ListTest1.push_back(FItem4);
    //    ListTest1.push_back(FItem3);
    //    ListTest1.remove(1);
    //    TS_ASSERT_EQUALS(ListTest1.get(1), 453.322);
    //}
    void test42SLLIFind()
    {
        Single_Linked_List<float> ListTest1;
        float FItem1 = 1.1;
        float FItem2 = 5.55;
        float FItem3 = 10.1010;
        float FItem4 = 453.322;
        size_t comp = 1;
        ListTest1.push_back(FItem1);
        ListTest1.push_back(FItem4);
        ListTest1.push_back(FItem3);
        ListTest1.sortedInsert(FItem2);
        TS_ASSERT_EQUALS(ListTest1.find(FItem2), comp);
    }
    //void test43SLLFFindException()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    float FItem2 = 5.55;
    //    float FItem3 = 10.1010;
    //    float FItem4 = 453.322;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem4);
    //    ListTest1.push_back(FItem3);
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.find(FItem2));
    //}
    //void test44SLLSRemoveException()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    float FItem2 = 5.55;
    //    float FItem3 = 10.1010;
    //    float FItem4 = 453.322;
    //    size_t comp = 10;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem4);
    //    ListTest1.push_back(FItem3);
    //    ListTest1.push_back(FItem2);
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.remove(comp));
    //}
    //void test45SLLFGetException()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    float FItem2 = 5.55;
    //    float FItem3 = 10.1010;
    //    float FItem4 = 453.322;
    //    size_t comp = 10;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem4);
    //    ListTest1.push_back(FItem3);
    //    ListTest1.push_back(FItem2);
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.get(comp));
    //}
    //void test46SLLFInsertException()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    float FItem2 = 5.55;
    //    float FItem3 = 10.1010;
    //    float FItem4 = 453.322;
    //    size_t comp = 10;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem4);
    //    ListTest1.push_back(FItem3);
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.insert(comp, FItem2));
    //}
    //void test47SLLFEmptyException()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    //float FItem2 = 5.55;
    //    float FItem3 = 10.1010;
    //    float FItem4 = 453.322;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem4);
    //    ListTest1.push_back(FItem3);
    //    ListTest1.~Single_Linked_List();
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.empty());
    //}
    //void test48SLLFFrontException()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    //float FItem2 = 5.55;
    //    float FItem3 = 10.1010;
    //    float FItem4 = 453.322;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem4);
    //    ListTest1.push_back(FItem3);
    //    ListTest1.~Single_Linked_List();
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.front());
    //}
    //void test49SLLFBackException()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    //float FItem2 = 5.55;
    //    float FItem3 = 10.1010;
    //    float FItem4 = 453.322;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem4);
    //    ListTest1.push_back(FItem3);
    //    ListTest1.~Single_Linked_List();
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.back());
    //}
    //void test50SLLFPopBackException()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //   // float FItem2 = 5.55;
    //    float FItem3 = 10.1010;
    //    float FItem4 = 453.322;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem4);
    //    ListTest1.push_back(FItem3);
    //    ListTest1.~Single_Linked_List();
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.pop_back());
    //}
    //void test51SLLFPopFrontException()
    //{
    //    Single_Linked_List<float> ListTest1;
    //    float FItem1 = 1.1;
    //    //float FItem2 = 5.55;
    //    float FItem3 = 10.1010;
    //    float FItem4 = 453.322;
    //    ListTest1.push_back(FItem1);
    //    ListTest1.push_back(FItem4);
    //    ListTest1.push_back(FItem3);
    //    ListTest1.~Single_Linked_List();
    //    TS_ASSERT_THROWS_ANYTHING(ListTest1.pop_front());
    //}

};
#endif /* NEWCXXTEST_H */ 
