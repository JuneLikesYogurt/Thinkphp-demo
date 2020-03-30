//创建对象

//工厂模式
function createPerson_Factory(name, age, job) {
    var o = new Object();
    o.name = name;
    o.age = age;
    o.job = job;
    o.sayName = function () {
        console.log(this.name);
    };

    return o;
}

var person1 = createPerson_Factory("Ann",19,"Doctor");
/**问题：
 * 无法知道一个对象的类型
 */




//构造函数模式
function createPerson_Constructer(name, age, job) {
    this.name = name;
    this.age = age;
    this.job = job;
    this.sayName = function () {
        console.log(this.name);
    }
}
var person1 = new createPerson_Constructer("Ann", 18 , "Engineer");
/*步骤：
    1. 创建一个新对象
    2. 将构造函数的作用域赋给新对象（this指向这个新对象）
    3. 执行构造函数中的代码（为这个新对象添加属性）
    4. 返回新对象
  问题：
    不同实例上的同名函数不相等（每new一个 createPerson 就会创建一个新的sayName）
*/




//原型模式
function createPerson_Prototype() {
}

// createPerson_Prototype.prototype.name = "xxx";
// createPerson_Prototype.prototype.age = 18;
// createPerson_Prototype.prototype.job = "teacher";
// createPerson_Prototype.prototype.sayName = function () {
//     console.log(this.name);
// }

createPerson_Prototype.prototype = {
    name = "xxx",
    age = 18,
    job : "teacher",
    sayName : function () {
        console.log(this.name);
    }
}
/**让所有对象实例共享它所包含的属性和方法 
 * 实例和原型由指针连接
 * 
*/




//组合使用构造函数和原型模式
function createPerson_con$pro (name, age, job) {
    this.name = name;
    this.age = age;
    this.job = job;
    this.friends = ["Tom", "John"];
}
createPerson_con$pro.prototype = {
    constructor : createPerson_con$pro,
    sayName : function () {
        console.log(this.name);
    }  
}

var person1 = new createPerson_con$pro("Jane", 10, "student");
var person2 = new createPerson_con$pro("Kangkang", 12, "student");
person1.friends.push("Van");

console.log(person1.friends); //Tom,John,Van
console.log(person2.friends); //Tom,John
/**缺点
 * 省略了为构造函数传递初始化参数环节
 */




//动态原型模式
function createPerson_DynamicProto(name, age, job) {
    this.name = name;
    this.age = age;
    this.job = job;

    if(typeof this.sayName != "function") {
        createPerson_DynamicProto.sayName = function () {
            console.log(this.name);
        }
    }
}
/**缺点
 * 不能用对象字面量重写原型（会切断现有实例与新原型之间的联系）
 */





//寄生函数构造模式
function createPerson_Parasitic (name, age, job) {
    var o = new Object ();
    o.name = name;
    o.age = age;
    o.job = job;
    o.sayName = function () {
        console.log(this.name);
    }
    return o;
}
var personX = new createPerson_Parasitic("Anne",45,"Engineer");
personX.sayName(); //"Anne"
/**返回的对象与构造函数or与构造函数的原型属性之间没有关系
 * 不能依赖instanceof来确定对象类型
 */



//稳妥构造函数模式
function createPerson_Durable(name, age, job) {
    var o = new Object();
    
    //在这里定义私有变量和函数

    o.sayName = function () {   //除了sayName没有其他办法能访问name的值
        console.log(name);
    }
    return o;
}
/**稳妥对象，没有公共属性，其方法也不引用this的对象 */