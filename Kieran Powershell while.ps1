$Value = 0
while($Value -ne 10){
    $Value = $Value+1
    #foreach($Thing in $Value){
     #   Write-Host "Hello!"
      #  }
    New-Item -ItemType Directory -Path C:\Users\$env:USERNAME\Documents\$Value
    Start-Sleep 2
    
    }