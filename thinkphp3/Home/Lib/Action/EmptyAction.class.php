<?php
	class EmptyAction extends Action{
		function index(){
			//$this->show('<p>该方法不存在</p>');
			
			$city=M('City');
    		$arr=$city->select();
    		$this->assign('list',$arr);
			// echo MODULE_NAME;
			 $name=MODULE_NAME;
			 $this->display("City:$name");
		}
	}
?>