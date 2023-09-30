# 현재디렉토리부터 모든 하위디렉토리에 있는 cpp와 h를 utf8(no-bom) 으로 저장.
Get-ChildItem -Recurse -Include *.cpp,*.h | ForEach-Object {
    $content = Get-Content $_.FullName
    Set-Content -Encoding utf8 -Path $_.FullName -Value $content
}