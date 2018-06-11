/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 10:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2018/06/03 10:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# include "ft_ssl.h"

# define CH_256(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ_256(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define S0_256(x) (ROTR_32(x, 2) ^ ROTR_32(x, 13) ^ ROTR_32(x, 22))
# define S1_256(x) (ROTR_32(x, 6) ^ ROTR_32(x, 11) ^ ROTR_32(x, 25))
# define D0_256(x) (ROTR_32(x, 7) ^ ROTR_32(x, 18) ^ ((x) >> 3))
# define D1_256(x) (ROTR_32(x, 17) ^ ROTR_32(x, 19) ^ ((x) >> 10))

# define ROTR_32(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

static uint32_t	g_t1[8];

static uint32_t	g_sha256_h[8] = {
	0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
	0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

static uint32_t g_sha256_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

char	*sha256_start(char *m, size_t len);
int		sha256_padding(char *m, uint64_t slen, uint32_t **nm);
void	sha256_process(uint32_t *x);
void	sha256_expand_words_amount(uint32_t *x, uint32_t *w);
void	sha256_add_and_equate_words(uint32_t *a, uint32_t *b, int op);
char	*sha256_output(uint32_t *hash);
char	*uint32_into_hex(uint32_t num);

#endif
