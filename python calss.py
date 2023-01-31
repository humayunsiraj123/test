class Item:
    def __init__(self,name :str,price :float ,quaitiy=0):
        assert 
        self.name=name
        self.price=price
        self.quaitiy=quaitiy
    def price(self):
        return self.price*self.quaitiy


item1=Item("apple",100,3)
print(item1.name)
print(item1.price())
print(item1.price)
