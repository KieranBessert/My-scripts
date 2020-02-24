#Coded by Kieran Bessert 5Mar2018
$val=1
$fileName = Read-Host "Enter path to csv file of /FIRSTNAME LASTNAME/"
$Users = Import-Csv -path $fileName

foreach ($user in $Users){
$fullName = $user.firstname + " " + $user.lastname 
$passWord = $user.tmppassword

#Take user input/ split to 2 objects/ structure usernames off of input/ makes all lower case
$newVar = $fullName.Split(" ")
$userName = $newVar[0].Substring(0,$val)+$newvar[1]
$userName = $userName.ToLower()

#If username already exsists, increase first name letter count by 1 until unique username
while (Get-LocalUser -Name $userName -ErrorAction SilentlyContinue) {
$val++
$userName = $newVar[0].Substring(0,$val)+$newvar[1]
$userName = $userName.ToLower()
}
#>

#Make the user account
New-LocalUser $userName -FullName $fullName -Password (ConvertTo-SecureString $Password -AsPlainText -Force)
}