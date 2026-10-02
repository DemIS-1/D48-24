/*-*- compile-command: "cc -c -o D48-24-fun.o -g -O3 -Wall -fno-strict-aliasing -ffp-contract=off -fPIC -I\"/usr/include/x86_64-linux-gnu\" D48-24-fun.c && cc -o D48-24-fun.so -shared -g -O3 -Wall -fno-strict-aliasing -ffp-contract=off -fPIC -Wl,-shared -Wl,-z,relro D48-24-fun.o -lc -lm -L/usr/lib/x86_64-linux-gnu -lpari"; -*-*/
#include <pari/pari.h>
/*
GP;install("init_D48_24_fun","v","init_D48_24_fun","./D48-24-fun.so");
GP;install("fun","vLLGLGLGLD0,G,D0,G,D0,G,GGD0,G,D0,G,D0,G,D0,G,D0,G,D0,G,","fun","./D48-24-fun.so");
GP;install("decode_task","D0,G,","decode_task","./D48-24-fun.so");
*/
void init_D48_24_fun(void);
void fun(long starti, long kolpop, GEN v, long maxpredp, GEN nu, long ip, GEN predp, long kolpredp, GEN n0, GEN log_name1, GEN nomtask, GEN bo, GEN T, GEN prter, GEN dopp, GEN pq, GEN pqrs, GEN kdel, GEN m);
GEN decode_task(GEN stkom);
/*End of prototype*/

void
init_D48_24_fun(void)	  /* void */
{
  pari_sp ltop = avma;
  avma = ltop;
  return;
}

void
fun(long starti, long kolpop, GEN v, long maxpredp, GEN nu, long ip, GEN predp, long kolpredp, GEN n0, GEN log_name1, GEN nomtask, GEN bo, GEN T, GEN prter, GEN dopp, GEN pq, GEN pqrs, GEN kdel, GEN m)	  /* void */
{
  pari_sp ltop = avma;
  long lenv;
  GEN ma = gen_0, n0a = gen_0;
  GEN ostma = gen_0, p1 = gen_0, ostn0a = gen_0, p2 = gen_0;	  /* vecsmall */
  GEN n = gen_0;	  /* int */
  long mes = 0;
  GEN kolfac = gen_0, p3 = gen_0;	  /* vecsmall */
  GEN pro = gen_0, p4 = gen_0;	  /* vec */
  long k48 = 0;
  GEN kanp = gen_0;	  /* int */
  GEN s_log_spaces = gen_0, mask_str = gen_0, spaces_after_n = gen_0, s_n = gen_0, sta = gen_0;
  long l5;
  if (typ(v) != t_VECSMALL)
    pari_err_TYPE("fun",v);
  if (typ(nu) != t_VECSMALL)
    pari_err_TYPE("fun",nu);
  if (typ(predp) != t_VECSMALL)
    pari_err_TYPE("fun",predp);
  if (typ(bo) != t_VECSMALL)
    pari_err_TYPE("fun",bo);
  if (typ(T) != t_VECSMALL)
    pari_err_TYPE("fun",T);
  lenv = lg(v)-1;
  ma = gmulgs(m, v[ip + 1]);
  n0a = gmulgs(n0, v[ip + 1]);
  {
    long nompr;
    p1 = cgetg(kolpredp+1, t_VECSMALL);
    for (nompr = 1; nompr <= kolpredp; ++nompr)
      p1[nompr] = gtos(gmodgs(ma, predp[nompr]));
  }
  ostma = p1;
  {
    long nompr;
    p2 = cgetg(kolpredp+1, t_VECSMALL);
    for (nompr = 1; nompr <= kolpredp; ++nompr)
      p2[nompr] = gtos(gmodgs(n0a, predp[nompr]));
  }
  ostn0a = p2;
  {
    long mes;
    p3 = cgetg(lenv+1, t_VECSMALL);
    for (mes = 1; mes <= lenv; ++mes)
      p3[mes] = 1;
  }
  kolfac = p3;
  {
    long mes;
    p4 = cgetg(lenv+1, t_VEC);
    for (mes = 1; mes <= lenv; ++mes)
      gel(p4, mes) = gen_1;
  }
  pro = p4;
  l5 = (starti + kolpop) - 1;
  {
    pari_sp btop = avma;
    long i;
    for (i = starti; i <= l5; ++i)
    {
      {
        long l6;
        long l7;	  /* lg */
        GEN p8 = gen_0;	  /* vecsmall */
        GEN p9 = gen_0;	  /* vec */
        long l10, l11;
        GEN p12 = gen_0;	  /* int */
        GEN p13 = gen_0;
        l6 = glength(prter);
        {
          pari_sp btop = avma;
          long j;
          for (j = 1; j <= l6; ++j)
          {
            if (gequalsg(bo[j], gmodsg(i, gel(prter, j))))
              goto label1;
            avma = btop;
          }
        }
        l7 = lg(T);
        {
          pari_sp btop = avma;
          long j;
          for (j = 1; j < l7; ++j)
          {
            if (gequalsg(T[j], gmodsg(i, gel(dopp, j))))
              goto label1;
            avma = btop;
          }
        }
        kanp = addii(n0, mulis(m, i));
        if (!(millerrabin(kanp,1)))
          continue;
        n = subis(mulsi(v[ip + 1], kanp), ip);
        {
          long mes;
          p8 = cgetg(lenv+1, t_VECSMALL);
          for (mes = 1; mes <= lenv; ++mes)
            p8[mes] = 1;
        }
        kolfac = p8;
        {
          long mes;
          p9 = cgetg(lenv+1, t_VEC);
          for (mes = 1; mes <= lenv; ++mes)
            gel(p9, mes) = gen_1;
        }
        pro = p9;
        {
          pari_sp btop = avma;
          long nompr;
          for (nompr = 1; nompr <= kolpredp; ++nompr)
          {
            mes = lenv - smodss((((ostn0a[nompr] + (ostma[nompr]*i)) - ip) + lenv) - 1, predp[nompr]);
            if (mes < 1)
              continue;
            ++kolfac[mes];
            gel(pro, mes) = gmulgs(gel(pro, mes), predp[nompr]);
            if (kolfac[mes] == nu[mes])
            {
              if (gequal0(gispseudoprime(gdiv(subis(addis(n, mes), 1), gmulsg(v[mes], gel(pro, mes))), 1)))
                goto label1;
            }
            if (gc_needed(btop, 1))
              gerepileall(btop, 2, &kolfac, &pro);
          }
        }
        {
          pari_sp btop = avma;
          long mes;
          for (mes = 1; mes <= lenv; ++mes)
          {
            if (kolfac[mes] < nu[mes])
            {
              if (!gequal0(gispseudoprime(gdiv(subis(addis(n, mes), 1), gmulsg(v[mes], gel(pro, mes))), 1)))
                goto label1;
            }
            avma = btop;
          }
        }
        l10 = glength(pq);
        {
          pari_sp btop = avma;
          long nom;
          for (nom = 1; nom <= l10; ++nom)
          {
            if (!gequal(numdiv(gsubgs(gadd(n, gel(pq, nom)), 1)), kdel))
              goto label1;
            avma = btop;
          }
        }
        l11 = glength(pqrs);
        {
          pari_sp btop = avma;
          long nom;
          for (nom = 1; nom <= l11; ++nom)
          {
            if (!gequal(numdiv(gsubgs(gadd(n, gel(pqrs, nom)), 1)), kdel))
              goto label1;
            avma = btop;
          }
        }
        p12 = addis(n, 15);
        {
          pari_sp btop = avma;
          GEN kan = gen_0;
          for (kan = n; gcmp(kan, p12) <= 0; kan = gaddgs(kan, 1))
          {
            if (gequal0(gmodgs(kan, 32)))
            {
              sta = gsubgs(kan, 15);
              break;
            }
            if (gc_needed(btop, 1))
              gerepileall(btop, 2, &sta, &kan);
          }
        }
        s_n = gcopy(GENtoGENstr(n));
        spaces_after_n = stoi(59 - glength(s_n));
        if (gcmpgs(spaces_after_n, 1) < 0)
          spaces_after_n = gen_1;
        mask_str = strtoGENstr("");
        p13 = gaddgs(sta, 30);
        {
          pari_sp btop = avma;
          GEN kan = gen_0;
          for (kan = sta; gcmp(kan, p13) <= 0; kan = gaddgs(kan, 1))
          {
            if (gequal(numdiv(kan), kdel))
            {
              ++k48;
              mask_str = Str(mkvec2(mask_str, strtoGENstr("1")));
            }
            else
              mask_str = Str(mkvec2(mask_str, strtoGENstr(" ")));
            if (gc_needed(btop, 1))
              gerepileall(btop, 2, &mask_str, &kan);
          }
        }
        if (k48 >= 20)
        {
          s_log_spaces = strtoGENstr("");
          {
            pari_sp btop = avma;
            GEN sp = gen_0;
            for (sp = gen_1; gcmp(sp, spaces_after_n) <= 0; sp = gaddgs(sp, 1))
            {
              s_log_spaces = Str(mkvec2(s_log_spaces, strtoGENstr(" ")));
              if (gc_needed(btop, 1))
                gerepileall(btop, 2, &s_log_spaces, &sp);
            }
          }
          write0(GENtostr_unquoted(log_name1), mkvecn(7, s_n, s_log_spaces, mask_str, strtoGENstr(" "), stoi(k48), strtoGENstr(" "), nomtask));
        }
        k48 = 0;
      }
      label1:;
      if (gc_needed(btop, 1))
        gerepileall(btop, 9, &n, &kolfac, &pro, &kanp, &s_log_spaces, &mask_str, &spaces_after_n, &s_n, &sta);
    }
  }
  avma = ltop;
  return;
}

GEN
decode_task(GEN stkom)	  /* vec */
{
  pari_sp ltop = avma;
  GEN skel_10 = gen_0;
  GEN p1 = gen_0;	  /* vec */
  GEN skel_100 = gen_0;
  GEN p2 = gen_0;	  /* vec */
  GEN skel_110 = gen_0;
  GEN p3 = gen_0;	  /* vec */
  GEN blocks_100 = gen_0;
  GEN p4 = gen_0;	  /* vec */
  GEN blocks_110 = gen_0;
  GEN p5 = gen_0;	  /* vec */
  GEN num_bolvanka = gen_0, p_17 = gen_0, p_19 = gen_0, p_23 = gen_0;
  GEN p6 = gen_0;	  /* vec */
  p1 = cgetg(11, t_VEC);
  gel(p1, 1) = gen_2;
  gel(p1, 2) = stoi(4);
  gel(p1, 3) = stoi(6);
  gel(p1, 4) = stoi(8);
  gel(p1, 5) = stoi(10);
  gel(p1, 6) = stoi(15);
  gel(p1, 7) = stoi(16);
  gel(p1, 8) = stoi(18);
  gel(p1, 9) = stoi(19);
  gel(p1, 10) = stoi(22);
  skel_10 = p1;
  p2 = cgetg(13, t_VEC);
  gel(p2, 1) = stoi(3);
  gel(p2, 2) = stoi(4);
  gel(p2, 3) = stoi(5);
  gel(p2, 4) = stoi(7);
  gel(p2, 5) = stoi(8);
  gel(p2, 6) = stoi(9);
  gel(p2, 7) = stoi(11);
  gel(p2, 8) = stoi(16);
  gel(p2, 9) = stoi(17);
  gel(p2, 10) = stoi(19);
  gel(p2, 11) = stoi(20);
  gel(p2, 12) = stoi(23);
  skel_100 = p2;
  p3 = cgetg(13, t_VEC);
  gel(p3, 1) = gen_2;
  gel(p3, 2) = stoi(3);
  gel(p3, 3) = stoi(4);
  gel(p3, 4) = stoi(6);
  gel(p3, 5) = stoi(7);
  gel(p3, 6) = stoi(8);
  gel(p3, 7) = stoi(10);
  gel(p3, 8) = stoi(15);
  gel(p3, 9) = stoi(16);
  gel(p3, 10) = stoi(18);
  gel(p3, 11) = stoi(19);
  gel(p3, 12) = stoi(22);
  skel_110 = p3;
  p4 = cgetg(6, t_VEC);
  gel(p4, 1) = stoi(8);
  gel(p4, 2) = stoi(9);
  gel(p4, 3) = stoi(11);
  gel(p4, 4) = stoi(16);
  gel(p4, 5) = stoi(17);
  blocks_100 = p4;
  p5 = cgetg(12, t_VEC);
  gel(p5, 1) = stoi(6);
  gel(p5, 2) = stoi(8);
  gel(p5, 3) = stoi(10);
  gel(p5, 4) = stoi(15);
  gel(p5, 5) = stoi(16);
  gel(p5, 6) = stoi(18);
  gel(p5, 7) = stoi(19);
  gel(p5, 8) = stoi(8);
  gel(p5, 9) = stoi(10);
  gel(p5, 10) = stoi(15);
  gel(p5, 11) = stoi(16);
  blocks_110 = p5;
  if (gcmpgs(stkom, 10) <= 0)
  {
    num_bolvanka = gen_1;
    p_17 = stoi(7);
    p_19 = stoi(3);
    p_23 = gcopy(gel(skel_10, gtos(stkom)));
  }
  else
  {
    if (gcmpgs(stkom, 110) <= 0)
    {
      GEN local_idx = gen_0, b = gen_0, sub_b = gen_0, step = gen_0;
      long l7 = 0;
      GEN local_found = gen_0;
      long l8;
      num_bolvanka = gen_2;
      local_idx = gsubgs(stkom, 10);
      b = gaddgs(gdiventgs(gsubgs(local_idx, 1), 20), 1);
      sub_b = gaddgs(gdiventgs(gmodgs(gsubgs(local_idx, 1), 20), 10), 1);
      step = gaddgs(gmodgs(gsubgs(local_idx, 1), 10), 1);
      p_17 = gcopy(gel(blocks_100, gtos(b)));
      if (gequal1(sub_b))
        l7 = 4;
      else
        l7 = 20;
      p_19 = stoi(l7);
      l8 = glength(skel_100);
      {
        pari_sp btop = avma;
        long k;
        for (k = 1; k <= l8; ++k)
        {
          if (gequal(gel(skel_100, k), p_17) || gequal(gel(skel_100, k), p_19))
            continue;
          local_found = gaddgs(local_found, 1);
          if (gequal(local_found, step))
          {
            p_23 = gcopy(gel(skel_100, k));
            break;
          }
          if (gc_needed(btop, 1))
            gerepileall(btop, 2, &p_23, &local_found);
        }
      }
    }
    else
    {
      if (gcmpgs(stkom, 220) <= 0)
      {
        GEN local_idx = gen_0, b = gen_0, step = gen_0, p_ext = gen_0, local_found = gen_0;
        long l9;
        num_bolvanka = stoi(3);
        local_idx = gsubgs(stkom, 110);
        b = gaddgs(gdiventgs(gsubgs(local_idx, 1), 10), 1);
        step = gaddgs(gmodgs(gsubgs(local_idx, 1), 10), 1);
        p_ext = gcopy(gel(blocks_110, gtos(b)));
        if (gcmpgs(b, 7) <= 0)
        {
          p_17 = stoi(7);
          p_19 = p_ext;
        }
        else
        {
          p_17 = p_ext;
          p_19 = stoi(3);
        }
        l9 = glength(skel_110);
        {
          pari_sp btop = avma;
          long k;
          for (k = 1; k <= l9; ++k)
          {
            if (gequal(gel(skel_110, k), p_17) || gequal(gel(skel_110, k), p_19))
              continue;
            local_found = gaddgs(local_found, 1);
            if (gequal(local_found, step))
            {
              p_23 = gcopy(gel(skel_110, k));
              break;
            }
            if (gc_needed(btop, 1))
              gerepileall(btop, 2, &p_23, &local_found);
          }
        }
      }
      else
        pari_err(e_MISC, "Invalid stkom!");
    }
  }
  p6 = cgetg(5, t_VEC);
  gel(p6, 1) = gcopy(p_17);
  gel(p6, 2) = gcopy(p_19);
  gel(p6, 3) = gcopy(p_23);
  gel(p6, 4) = gcopy(num_bolvanka);
  p6 = gerepilecopy(ltop, p6);
  return p6;
}

