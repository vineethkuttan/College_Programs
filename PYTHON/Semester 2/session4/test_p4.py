'''
Created on Jan 30, 2019

@author: Lenovo
'''
import unittest
from session4 import p4
class Testp4(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        print("Set UP class")
    @classmethod
    def tearDownClass(cls):
        print("Teardown class")
    def setUp(self):
        self.obj1=p4.SumOfMultiples()
        self.obj2=p4.LeapYear()  
    def test_get_sum_of_multiples1(self):
        self.assertEqual(self.obj1.get_sum_of_multiples(4,[3,5]),3)
    def test_get_sum_of_multiples2(self):
        self.assertEqual(self.obj1.get_sum_of_multiples(4,[3,4]),7)
    def test_get_sum_of_multiples3(self):
        self.assertNotEqual(self.obj1.get_sum_of_multiples(4,[3,5]),8)
    def test_get_sum_of_multiples4(self):
        self.assertNotEqual(self.obj1.get_sum_of_multiples(4,[3,4]),3)
    def test_get_sum_of_multiples5(self):
        self.assertEqual(self.obj1.get_sum_of_multiples(4,[3,2]),5)
    def test_get_sum_of_multiples6(self):
        self.assertNotEqual(self.obj1.get_sum_of_multiples(4,[3,5]),9)
    def test_get_sum_of_multiples7(self):
        self.assertNotEqual(self.obj1.get_sum_of_multiples(4,[3,5]),10)
    def test_get_sum_of_multiples8(self):
        self.assertNotEqual(self.obj1.get_sum_of_multiples(4,[3,5]),11)
    def test_get_sum_of_multiples9(self):
        self.assertNotEqual(self.obj1.get_sum_of_multiples(4,[3,5]),12)
    def test_get_sum_of_multiples10(self):
        self.assertNotEqual(self.obj1.get_sum_of_multiples(4,[3,5]),13)
    def test_checkleap1(self):
        self.assertMultiLineEqual(self.obj2.checkleap(2004),"Leap year")
    def test_checkleap2(self):
        self.assertMultiLineEqual(self.obj2.checkleap(2008),"Leap year")
    def test_checkleap3(self):
        self.assertMultiLineEqual(self.obj2.checkleap(2012),"Leap year")
    def test_checkleap4(self):
        self.assertMultiLineEqual(self.obj2.checkleap(2016),"Leap year")
    def test_checkleap5(self):
        self.assertMultiLineEqual(self.obj2.checkleap(2024),"Leap year")
    def test_checkleap6(self):
        self.assertMultiLineEqual(self.obj2.checkleap(2003),"Not a leap year")
    def test_checkleap7(self):
        self.assertMultiLineEqual(self.obj2.checkleap(2005),"Not a leap year")
    def test_checkleap8(self):
        self.assertMultiLineEqual(self.obj2.checkleap(2006),"Not a leap year")
    def test_checkleap9(self):
        self.assertMultiLineEqual(self.obj2.checkleap(2007),"Not a leap year")
    def test_checkleap10(self):
        self.assertMultiLineEqual(self.obj2.checkleap(2009),"Not a leap year")
    def tearDown(self):
        del self.obj1
        del self.obj2
if __name__=="__main__":
    unittest.main()
        
        