//继承

//借用构造函数
function SuperType_constructor() {
    this.color = ["red","blue","green"];
}
function SubType_constructor() {
    //继承了SuperTpye_constructor
    SuperType_constructor.call(this);
}
var instance1 = new SubType_constructor();
instance1.color.push("pink");
console.log(instance1.color); //red,blue,green,pink

var instance2 = new SubType_constructor();
console.log(instance2.color); //red,blue,green



//组合继承
function SuperType_combination(name) {
    this.name = name;
    this.color = ["red","blue","green"];
}
SuperType_combination.prototype.sayName = function () {
    console.log(this.name);
}

function SubType_combination(name,age) {    //第二次调用SuperType()
    SuperType_combination.call(this,name);
    this.age = age;
}

SubType_combination.prototype = new SuperType_combination();    //第一次调用SuperType()
SubType_combination.prototype.constructor = SubType_combination;
SubType_combination.prototype.sayAge = function () {
    console.log(this.age);
}



//原型式继承
function object(o) {
    function F() {}
    F.prototype = o;
    return new F();
}
var person = {
    name: "Jane",
    friends : ["Mike", "Van"]
}
var anotherPerson = object.create(person, {
    name: {
        value: "Greg"
    }
});
console.log(person.name); //Greg




//寄生式继承
function createAnother (original) {
    var clone = object(original);   //通过调用函数创建一个新对象
    clone.sayHi = function () {     //以某种方式增强这个对象
        console.log("hi");
    }
    return clone;
}




//寄生组合继承
function inheritPrototype (subTpye, superType) {
    var prototype = object(subTpye,superType);  //创建对象
    prototype.constructor = subTpye;    //增强对象，弥补重写原型而失去的默认的constructor属性
    subTpye.prototype = prototype;  //指定对象，赋给子类
}