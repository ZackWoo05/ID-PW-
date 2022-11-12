# ID & PW 저장 프로그램

## 프로젝트 소개 📢
• 아이디 비밀번호를 RSA 암호화 알고리즘을 이용하여 안전하고 간편하게 저장하는 프로그램입니다.

## 개발기간 🗓
• 2021.03.12~2022.11.12

# 개요 💻
• 저장

  1-1. 아이디, 사이트 주소 및 비밀번호 입력
  
  1-2. 비밀번호 암호화 및 key.txt(DataBase) 에 RSA 알고리즘 키를 저장
  
  1-3. 암호화 된 비밀번호와 아이디, 사이트 주소를 사이트주소|아이디|암호화된 비밀번호 형식으로 db.txt에 저장
  
• 확인

  2-1. 사이트 주소 입력
  
  2-2. db.txt 에서 사이트 주소와 일치한 값을 찾음
  
  2-3. key.txt에 들어있는 키와 db.txt에 있는 암호화된 비밀번호를 RSA 알고리즘으로 복호화
  
  2-4. 복호화된 비밀번호와 아이디를 출력

# 개발환경 ⛏
• c++ 

# 향후계힉 🔬
• 홈페이지에서 구동(http://zackey.kr)
