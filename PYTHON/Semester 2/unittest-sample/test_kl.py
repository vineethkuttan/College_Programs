'''
Created on 21-Jan-2019

@author: student
'''
import unittest
from unittestvin import kl
class Test1(unittest.TestCase):
    def test_add(self):
        result=kl.add(10,5)
        self.assertEqual(result,15)
        self.assertEqual(kl.add(1,-1),0)
    def test_divide(self):
        """self.assertEqual(kl.divide(1,1),53,"king maker")
        self.assertRaises(ValueError,kl.divide,10,0)"""
        with self.assertRaises(ValueError):
            kl.divide(10,0)
    def test_checking(self):
        self.assertTrue(1)
    def test_checking2(self):
        self.assertFalse(0)
    def test_checking3(self):
        self.assertIs(1, 1)
    def test_checking4(self):        
        self.assertIsNot(1,3)
    def test_checking5(self):
        self.assertIsNone(None)
    def test_checking6(self):
        self.assertIsNotNone(1)
    def test_checking7(self):        
        self.assertIn(1,[1,2])
    def test_checking8(self):
        self.assertNotIn(3,[1,2])
    def test_checking9(self):
        self.assertIsInstance("bar",str)#isinstance(foo, (str, int, float)) ==True where foo="vineeth"
    def test_checking10(self):
        self.assertNotIsInstance(1,str)
    def test_checking11(self):
        self.assertAlmostEqual(1-1,0)
    def test_checking12(self):
        self.assertGreater(2,1)
    def test_checking13(self):
        self.assertGreaterEqual(1,1)
    def test_checking14(self):
        self.assertLess(1,2)
    def test_checking15(self):
        self.assertLessEqual(1,1)
    """def test_checking16(self):
        self.assertRegex("hello","hello hi")
    def test_checking17(self):
        self.assertNotRegex("ee","hello")"""
    """def test_checking18(self):
        self.assertCountEqual([1,1,2],[2,1,1])"""
    def test_checking19(self):
        self.assertMultiLineEqual("vibe","vibe")
    def test_checking20(self):
        self.assertSequenceEqual([1,2,3],(1,2,3))
    def test_checking21(self):
        self.assertListEqual([1,2], [1,2])
    def test_checking22(self):
        self.assertTupleEqual((1,2,3),(1,2,3))
    def test_checking23(self):
        self.assertSetEqual({1,3,2},{3,2,1})
    def test_checking24(self):
        self.assertDictEqual({2:1,1:2},{1:2,2:1})
if __name__=="__main__":
    unittest.main()