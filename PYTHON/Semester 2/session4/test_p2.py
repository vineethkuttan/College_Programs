'''
Created on Jan 30, 2019

@author: Lenovo
'''
import unittest
from session4 import p2
class Testp2(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        print("Set UP class")
    @classmethod
    def tearDownClass(cls):
        print("Teardown class")
    def setUp(self):
        self.Robj1=p2.Rectangle(5,10,"red")
        self.Robj2=p2.Rectangle(15,10,"green")
    def test_get_area(self):
        self.assertEqual(self.Robj1.get_area(),50)
        self.assertEqual(self.Robj2.get_area(),150)
    def test_todisplay(self):
        self.assertMultiLineEqual(self.Robj1.todisplay(), "Area of rectangle 50\nred in color")
        self.assertMultiLineEqual(self.Robj2.todisplay(), "Area of rectangle 150\ngreen in color")
    def tearDown(self):
        del self.Robj1
        del self.Robj2
if __name__=="__main__":
    unittest.main()
