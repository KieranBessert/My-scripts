#Scripted by Kieran Bessert 7MAR2019
$Password = "April 29, 2005"
$myArray = @()
$myArray += 1..1000 | ForEach-Object {Get-Random -Minimum 0 -Maximum 1000 }
if ($myArray -contains 42){
Write-Host "The answer to life the universe and everything is found"
} else {
    if (Get-LocalUser -Name dadams -ErrorAction SilentlyContinue) {
    Remove-LocalUser dadams
    Write-Host "So long and thanks for all the fish"
    } else {
    New-LocalUser dadams -FullName "Douglas Adams" -Password (ConvertTo-SecureString $Password -AsPlainText -Force)
    Write-Host "He is born"
} }

#This does Nothing