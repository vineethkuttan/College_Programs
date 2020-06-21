'''
Created on Jan 30, 2019

@author: Lenovo
'''
class Rectangle:
    def __init__(self,length,width,colour):
        self.__length=length
        self.__width=width
        self.__colour=colour
    
    def get_length(self):
        return self.__length
        
    
    def get_width(self):
        return self.__width
    
    
    def get_colour(self):
        return self.__colour
    
    
    def set_length(self, value):
        self.__length = value
    
    
    def set_width(self, value):
        self.__width = value
    
    
    def set_colour(self, value):
        self.__colour = value
    
    def get_area(self):
        return self.get_length()*self.get_width()
    def todisplay(self):
        k1,k2=self.get_area(),self.get_colour()
        return f"Area of rectangle {k1}\n{k2} in color"
