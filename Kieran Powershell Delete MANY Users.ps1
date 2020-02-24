$users = Get-LocalUser
$passDate = $users.passwordlastset
$passdate = $passDate.ToString("yyyyMMdd")
$today = Get-Date
$today = $today.ToString("yyyyMMdd")
$passDate
$today
#foreach($user in $users)