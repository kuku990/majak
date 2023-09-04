class Product:
    def __init__(self, name, length, width, height, dimension_unit, weight, weight_unit, quantity):
        self.name = name
        self.length = length
        self.width = width
        self.height = height
        self.dimension_unit = dimension_unit
        self.weight = weight
        self.weight_unit = weight_unit
        self.quantity = quantity

class SizeClass:
    def __init__(self, name, min_dim, max_dim, min_weight, max_weight, price):
        self.name = name
        self.min_dim = min_dim
        self.max_dim = max_dim
        self.min_weight = min_weight
        self.max_weight = max_weight
        self.price = price

sizeClasses = [
    SizeClass("X-Small", 0.0, 25.0, 0.0, 1000.0, 100),
    SizeClass("Small", 0.0, 55.0, 0.0, 5000.0, 200),
    SizeClass("Medium", 0.0, 105.0, 0.0, 25000.0, 300)
    # SizeClass("Large", 0.0, 105.0, 0.0, 25000.0, 400)
]

def get_price_based_unit(product):
    length = product.length
    width = product.width
    weight = product.weight
    max_dim = 0.0
    unit_price = 0.0

    # Convert dimensions and weight to appropriate units
    if product.dimension_unit == "M":
        max_dim *= 100.0
    if product.weight_unit == "KG":
        weight *= 1000.0
    
    max_dim = length + width

    for size_class in sizeClasses:
        if size_class.min_dim <= max_dim <= size_class.max_dim and size_class.min_weight <= weight <= size_class.max_weight:
            unit_price = size_class.price
            break
        elif max_dim > 0 and weight >0 :
            unit_price = 400

    return unit_price

if __name__ == "__main__":
    products = [
        Product("ToyOne", 90, 50, 40, "CM", 8000, "GM", 45),
        Product("ToyTwo", 1.2, 0.3, 0.2, "M", 9000, "GM", 28)
    ]

    total_cost = 0

    for product in products:
        unit_price = get_price_based_unit(product)
        total_cost += unit_price * product.quantity

    print("Total fulfillment cost: $", total_cost)
