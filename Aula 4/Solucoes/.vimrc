set relativenumber
:au BufNewFile *.cpp r ~/vim/templates/template.cpp
set ts=4 sw=4 stl+=%F smartindent
set bg=dark ruler clipboard=unnamed,unnamedplus timeoutlen=100
imap {<CR> {<CR>}<Esc>O
nmap <F2> 0V$%d
nmap <C-down> :m+1<CR>
nmap <C-up> :m-2<CR>
vmap <C-c> "+y
nmap <C-a> ggVG
syntax on
