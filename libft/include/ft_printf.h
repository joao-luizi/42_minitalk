/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:04:38 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:51:02 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"
// ft_printf
typedef struct s_info_list
{
	void				*content;
	struct s_info		*info;
	struct s_info_list	*next;
}						t_info_list;

typedef struct s_info
{
	char				flags;
	int					width;
	int					precision;
	int					specifier;
	char				padding;
	size_t				str_len;
}						t_info;

enum					e_flags
{
	MINUS = (1 << 0),
	PLUS = (1 << 1),
	SPACE = (1 << 2),
	CARDINAL = (1 << 3),
	ZERO = (1 << 4)
};

enum					e_specifier
{
	ERROR = -1,
	NONE = 0,
	c = 1,
	s = 2,
	p = 3,
	d = 4,
	i = 5,
	u = 6,
	x = 7,
	X = 8,
	pc = 9
};
// ft_printf.c
int						ft_printf(const char *format, ...);
char					*get_formatted_string(t_info *info, char *content,
							va_list *args);
// auxiliary functions ft_utils.c

char					*ft_itoabase(int nbr, char *base_to);
char					*ft_utoabase(long nbr, char *base_to);

// auxiliary functions ft_utils2.c
int						ft_iswhitespace(char c);
int						ft_ischarinlist(char *lst, char c);
size_t					ft_inbrlen(int nbr, char *base);
size_t					ft_lnbrlen(long nbr, char *base_to);
void					i_number_tobuffer(int nbr, char *base, int bf_size,
							char *bf);
void					l_number_tobuffer(long nbr, char *base, int bf_size,
							char *bf);

// auxiliary functions ft_utils3.c
t_info_list				*get_new_lst(char *content, va_list *args);
// auxiliary function ft_utils4.c
void					format_info(t_info *info, char *content, va_list *args);
char					*ft_prepend(char *str, char *original);

// auxiliary function ft_utils5.c
char					get_flags(char *str, int *i);
int						get_width(char *str, va_list *args, int *i);
int						get_precision(char *str, va_list *args, int *i);
char					*c_handler(t_info *info, va_list *args);
char					*s_handler(t_info *info, va_list *args);
char					*p_handler(t_info *info, va_list *args);
char					*d_handler(t_info *info, va_list *args);
char					*u_handler(t_info *info, va_list *args);
char					*x_handler(t_info *info, va_list *args, char c);
char					*x_get_string_number(t_info *info, unsigned int nbr,
							char *base, char c);
size_t					get_final_width(int precision, int width,
							int char_count);
char					*final_string(char *src, size_t min_width,
							size_t max_char, t_info *info);

// auxiliary function ft_utils6.c
int						ft_lstprint(t_info_list *lst);
void					free_list(t_info_list **lst);
void					ft_info_lst_add_back(t_info_list **lst,
							t_info_list *new);
size_t					ft_strlenif(char *str, char *lst);
#endif
