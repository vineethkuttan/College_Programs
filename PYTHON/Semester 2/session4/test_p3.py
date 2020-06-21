'''
Created on Jan 30, 2019

@author: Lenovo
'''
import unittest
from session4 import p3
class Testp3(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        print("Set UP class")
    @classmethod
    def tearDownClass(cls):
        print("Teardown class")
    def setUp(self):
        self.obj1=p3.Employee("vineeth","kuttan",300,5)
        self.obj2=p3.Employee("ram","kumar",400,4)  
    def test_email(self):
        self.assertMultiLineEqual(self.obj1.email(),"vineeth.kuttan@email.com")
        self.assertMultiLineEqual(self.obj2.email(),"ram.kumar@email.com")
    @unittest.skipIf(1>0,"skip this routine")
    def test_monthly_incentive(self):
        self.assertEqual(self.obj1.monthly_incentive(50),350)  
        self.assertEqual(self.obj2.monthly_incentive(50),450)  
    @unittest.expectedFailure
    def test_apply_raise(self):
        self.obj1.apply_raise()
        self.obj2.apply_raise()
        self.assertEqual(525,self.obj1.pay)
        self.assertEqual(675,self.obj2.pay)
    def tearDown(self):
        del self.obj1
        del self.obj2
if __name__=="__main__":
    unittest.main()
        