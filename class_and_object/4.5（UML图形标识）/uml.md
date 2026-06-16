classDiagram
    class Customer {
        +String name
        +String phone
        +placeOrder() void
    }

    class Order {
        +String orderId
        +Date createTime
        +calculateTotal() float
    }

    class MenuItem {
        +String name
        +float price
    }

    class MainCourse {
        +boolean isSpicy
    }

    class Beverage {
        +boolean hasIce
    }

    %% 下面是定义类与类之间的关系
    Customer "1" --> "*" Order : 关联 (下单)
    Order o-- MenuItem : 聚合 (包含)
    MenuItem <|-- MainCourse : 继承
    MenuItem <|-- Beverage : 继承