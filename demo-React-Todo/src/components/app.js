/**
 * 顶层index页面
 */
//alert('success')

import React from 'react'
import ReactDOM from 'react-dom'
import TodoHeader from './TodoHeader' //引入TODOHeader组件
import TodoMain from './TodoMain'	//引入TodoMain组件

class App extends React.Component { //定义组件，继承父类
  constructor() {//constructor 是和 class 一起用来创建和初始化对象的特殊方法。
    super()//在装载组件(mounting)之前调用会React组件的构造函数。当实现React.Component子类的构造函数时，应该在任何其他语句之前调用super(props)
    this.state = {//设置初始状态
      todos: []
    }
  }

  // // 绑定键盘回车事件，添加新任务
  // handlerKeyUp(e) {
  //   if(e.keyCode == 13) {
  //     let value = e.target.value;
  //     if(!value) return false;
  //     let newTodoItem = {
  //       text: value,
  //       isDone: false
  //     };
  //     e.target.value = '';
  //     this.state.todos.push(newTodoItem)
  //     this.setState({todos: this.state.todos});  //修改状态值，每次修改以后，自动调用 this.render 方法，再次渲染组件。
  //   }
  // }
  // render(){
  //   return (
  //     <div className="todo-input">
  //       <input type="text" placeholder="请输入待办事项" onKeyUp={this.handlerKeyUp.bind(this)}/>
  //       <ul>
  //         {this.state.todos.map((todo,index) => {{
  //           return (
  //               <li key={index}>{todo.text}</li>//Keys help React identify which items have changed, are added, or are removed. Keys should be given to the elements inside the array to give the elements a stable identity
  //           )
  //         }})}
  //       </ul>
  //     </div>
  //   )
  // }

  addTodo(item) {	//新增了添加todo事项的方法
  	this.state.todos.push(item)
  	this.setState({todos:this.state.todos});	//设置状态
  }
  render() {
  	return (
  			//将原内容卸载组件中并引入进行渲染
  			//把addTodo方法传递到TodoHeader组件中，bind(this)是为了把改React实例绑定到this上
  		<div className="todo-wrapper">
  			<TodoHeader addTodo={this.addTodo.bind(this)}/>		
  			<TodoMain todos={this.state.todos}/>
  		</div>//把state.todos传入到TodoMain中
  	)
  }
}


ReactDOM.render(<App/>,document.getElementById('app'))
