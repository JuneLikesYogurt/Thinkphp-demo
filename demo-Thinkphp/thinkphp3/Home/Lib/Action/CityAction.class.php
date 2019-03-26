<?php
	/**
	* 
	*/
	class CityAction extends Action{
		function bj(){
			// $city=M('City');
   //  		$arr=$city->select();
   //  		$this->assign('list',$arr);
			// $this->display();
			$oi=new IndexAction();
			$oi->index();
		}
		function sh(){
			// $city=M('City');
   //  		$arr=$city->select();
   //  		$this->assign('list',$arr);
			// $this->display();
			$oi=new IndexAction();
			$oi->index();
		}
		function gz(){
			// $city=M('City');
   //  		$arr=$city->select();
   //  		$this->assign('list',$arr);
			// $this->display();
			$oi=new IndexAction();
			$oi->index();
		}
		function _empty($name){
			$this->show("$name 不存在  <a href='__APP__/Index/index'>返回首页</a>");
		}
	}
?>