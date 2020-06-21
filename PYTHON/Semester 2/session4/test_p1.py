'''
Created on Jan 30, 2019

@author: Lenovo
'''
import unittest
from session4 import p1
class Testp1(unittest.TestCase):
    def test_is_isogram1(self):
        self.assertFalse(p1.is_isogram("Vineeth;;"), "check your data")
    def test_is_isogram2(self):
        self.assertFalse(p1.is_isogram("aravind"), "check your data")
    def test_is_isogram3(self):
        self.assertTrue(p1.is_isogram("gowtham"), "check your data")
    def test_is_isogram4(self):
        self.assertFalse(p1.is_isogram("saihari99;"), "check your data")
    def test_is_isogram5(self):
        self.assertFalse(p1.is_isogram("Dhinesh;;"), "check your data")
    def test_is_isogram6(self):
        self.assertFalse(p1.is_isogram("Giri;"), "check your data")
    def test_is_isogram7(self):
        self.assertFalse(p1.is_isogram("Udhaya;;"), "check your data")
    def test_is_isogram8(self):
        self.assertTrue(p1.is_isogram("Rajesh;"), "check your data")
    def test_is_isogram9(self):
        self.assertTrue(p1.is_isogram("King,er;;"), "check your data")
    def test_is_isogram10(self):
        self.assertTrue(p1.is_isogram("Vin00eth;;"), "check your data")
if __name__=="__main__":
    unittest.main()
